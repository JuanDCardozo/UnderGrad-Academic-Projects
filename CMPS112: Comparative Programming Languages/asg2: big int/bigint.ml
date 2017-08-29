
open Printf

module Bigint = struct

    type sign     = Pos | Neg
    type bigint   = Bigint of sign * int list
    let  radix    = 10
    let  radixlen =  1

    let car       = List.hd
    let cdr       = List.tl
    let map       = List.map
    let reverse   = List.rev
    let strcat    = String.concat
    let strlen    = String.length
    let strsub    = String.sub
    let zero      = Bigint (Pos, [])

    let register = Array.make 256 (false, zero)
    let rget = Array.get
    let rset = Array.set

    let charlist_of_string str =
        let last = strlen str - 1
        in  let rec charlist pos result =
            if pos < 0
            then result
            else charlist (pos - 1) (str.[pos] :: result)
        in  charlist last []

    let bigint_of_string str =
        let len = strlen str
        in  let to_intlist first =
                let substr = strsub str first (len - first) in
                let digit char = int_of_char char - int_of_char '0' in
                map digit (reverse (charlist_of_string substr))
            in  if   len = 0
                then zero
                else if   str.[0] = '_'
                     then Bigint (Neg, to_intlist 1)
                     else Bigint (Pos, to_intlist 0)

    let string_of_bigint (Bigint (sign, value)) =
        match value with
        | []    -> "0"
        | value -> let reversed = reverse value
                   in  strcat ""
                       ((if sign = Pos then "" else "-") ::
                        (map string_of_int reversed))

    let rec addRec list1 list2 carry = match (list1, list2, carry) with
        | list1, [], 0       -> list1
        | [], list2, 0       -> list2
        | list1, [], carry   -> addRec list1 [carry] 0
        | [], list2, carry   -> addRec [carry] list2 0
        | car1::cdr1, car2::cdr2, carry ->
          let sum = car1 + car2 + carry
          in  sum mod radix :: addRec cdr1 cdr2 (sum / radix)

    let rec subRec list1 list2 carry = match (list1, list2, carry) with
        | list1, [], 0       -> list1
        | [], list2, 0       -> list2
        | list1, [], carry   -> subRec list1 [carry] 0
        | [], list2, carry   -> subRec [carry] list2 0
        | car1::cdr1, car2::cdr2, carry ->
          let diff = car1 - car2 - carry
          in diff mod radix :: subRec cdr1 cdr2 (diff / radix)

  (*CMP Function *)
  let cmpCheck car1 car2 =
    if car1 < car2
      then 0
    else if car2 < car1
      then 1
    else -1

  let rec cmp list1 list2 = match (list1, list2) with
         | list1, []                 -> 1
         | [], list2                 -> 0
         | car1::cdr1, car2::cdr2    ->
          if (cmpCheck car1 car2) < 0 then (cmp cdr1 cdr2)
            else (cmpCheck car1 car2)

  (* add function *)
   let add (Bigint (sign1, value1)) (Bigint (sign2, value2)) =
    if sign1 = sign2
      then Bigint (sign1, addRec value1 value2 0)
    else if (cmp value1 value2) = 1
      then (
        if (sign1 = Neg && sign2 = Pos)
          then Bigint(sign1, subRec value1 value2 0)
        else if (sign1 = Pos && sign2 = Neg)
          then  Bigint(sign1, subRec value1 value2 0)
        else Bigint(sign1, subRec value1 value2 0)
      )
    else (
      if (sign1 = Neg && sign2 = Pos)
        then Bigint(sign2, subRec value2 value1 0)
      else if (sign1 = Pos && sign2 = Neg)
        then Bigint(sign2, subRec value2 value1 0)
      else Bigint(sign2, subRec value2 value1 0)
      )


  (* sub function*)
  let sub (Bigint (sign1, minuend)) (Bigint (sign2, subtrahend)) =
  if (cmp minuend subtrahend) = 0
   then(
     if (sign1 = Pos && sign2 = Pos)
       then Bigint (Neg, subRec minuend subtrahend 0)
     else if (sign1 = Neg && sign2 = Neg)
      then Bigint(Pos, subRec minuend subtrahend 0)
     else Bigint(sign1, addRec minuend subtrahend 0)
   )
   else if (cmp minuend subtrahend) = 1
      then (
        if (sign1 = Pos && sign2 = Pos)
          then Bigint (sign1, subRec minuend subtrahend 0)
        else if (sign1 = Neg && sign2 = Neg)
         then Bigint(sign1, addRec minuend subtrahend 0)
       else Bigint(sign1, addRec minuend subtrahend 0)
      )
    else Bigint(sign1, addRec minuend subtrahend 0)

  (* mul function *)
  let rec mulRec multiplicand multiplier =
       if (car multiplier) <> 1
          then (addRec multiplicand (mulRec multiplicand (subRec multiplier [1] 0)) 0)
       else multiplicand

  let mul (Bigint (sign1, multiplicand)) (Bigint (sign2, multiplier)) =
   if sign1 = sign2
    then Bigint(Pos, mulRec multiplicand multiplier)
   else Bigint(Neg, mulRec multiplicand multiplier)

  (* div function *)
  let rec divRec dividend divisor quotient =
          if (cmp dividend divisor) <> 0
            then (divRec (subRec dividend divisor 0) divisor (addRec quotient [1] 0))
          else (quotient, dividend)

  let div (Bigint (sign1, dividend)) (Bigint (sign2, divisor)) =
      if (car divisor) = 0
        then ( printf "Cannot Divide by zero\n"; zero)
      else if sign1 = sign2
        then Bigint(Pos, fst(divRec dividend divisor [0]))
      else Bigint(Neg, fst(divRec dividend divisor [0]))

  (* rem function *)
  let rem (Bigint (sign1, dividend)) (Bigint (sign2, divisor)) =
      if (car divisor) = 0
        then (printf "Remainder by zero\n"; zero)
      else if sign1 <> sign2
            then Bigint(Neg, snd(divRec dividend divisor [0]))
     else Bigint(sign1, snd(divRec dividend divisor [0]))


  (* pow function *)
  let rec powRec base exponent =
          if (car exponent) = 1
            then base
          else (mulRec base (powRec base (subRec exponent [1] 0)))

  let pow (Bigint (sign1, base)) (Bigint (sign2, exponent)) =
      if sign2 = Pos
        then (Bigint (sign1, powRec base exponent))
      else if sign1 = Neg
         then (zero)
      else if rem (Bigint (Pos, exponent)) (Bigint (Pos, [2])) =
        (Bigint (Pos, [1]))
                     then (Bigint (Neg, powRec base exponent))
      else (Bigint (Pos, powRec base exponent))

   let store (Bigint(sign1,value)) reg = rset register(reg) (true, Bigint(sign1,value))

   let load stack reg =  let entry = rget register (reg)
              in match entry with
                | false, _ -> printf "register '%n' is empty\n%!" reg
                | true, Bigint(sign1,value) -> Stack.push (Bigint(sign1,value)) stack
end
