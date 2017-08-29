***********************************************************************
* Assignment: Asg1
* Name: Juan D. Cardozo
* Student ID: 1362585
* Cruz ID: jcardozo
* Submitted: sbi.scm README
* Note: 
**********************************************************************
;; $Id: sbi.scm,v 1.3 2016-09-23 18:23:20-07 - - $
;;
;; NAME
;;    sbi.scm - silly basic interpreter
;;
;; SYNOPSIS
;;    sbi.scm filename.sbir
;;
;; DESCRIPTION
;;    The file mentioned in argv[1] is read and assumed to be an SBIR
;;    program, which is the executed.  Currently it is only printed.
;;
;; STUDENT ID: 1362585

(define *stderr* (current-error-port))

(define *run-file*
    (let-values
        (((dirpath basepath root?)
            (split-path (find-system-path 'run-file))))
        (path->string basepath))
)

(define (die list)
    (for-each (lambda (item) (display item *stderr*)) list)
    (newline *stderr*)
    (exit 1)
)

(define (usage-exit)
    (die `("Usage: " ,*run-file* " filename"))
)

(define (readlist-from-inputfile filename)
    (let ((inputfile (open-input-file filename)))
         (if (not (input-port? inputfile))
             (die `(,*run-file* ": " ,filename ": open failed"))
             (let ((program (read inputfile)))
                  (close-input-port inputfile)
                         program))))

(define (write-program-by-line filename program)
    (printf "==================================================~n")
    (printf "~a: ~s~n" *run-file* filename)
    (printf "==================================================~n")
    (printf "(~n")
    (map (lambda (line) (printf "~s~n" line)) program)
    (printf ")~n"))

(define (main arglist)
    (if (or (null? arglist) (not (null? (cdr arglist))))
        (usage-exit)
(let* ((sbprogfile (car arglist))
               (program (readlist-from-inputfile sbprogfile)))
               (write-program-by-line sbprogfile program)
			   (storeLabel program)
			   (execute program))))

;; Creates a function table
(define *function-table* (make-hash))

;; Way to get the functions from table
(define (function-get key)
	(hash-reference *function-table* key))
	
;; Way to put functions in table
(define (function-put! key value)
	(hash-set!  key value))

(for-each
	(lambda(pair)
		(function-put! (car pair)(cadr pair)))
	`(
		(abs	 ,(lambda (x) (abs x)))
        (log10   ,(lambda (x) (/ (log x) (log 10.0))))
		(log2	 ,(lambda (x) (/ (log x) (log 2.0))))
		(acos	 ,acos)
		(asin	 ,asin)
		(atan	 ,atan)
		(/	 ,/)
		(trunc	 ,truncate)
		(round	 ,round)
       	(+       ,+)
		(-	 ,-)
		(*	 ,*)
       	(^       ,expt)
       	(ceil    ,ceiling)
      	(exp     ,exp)
       	(floor   ,floor)
       	(log     ,log)
       	(sqrt    ,sqrt)
		(tan	 ,tan)
		(cos	 ,cos)
		(sin	 ,sin)
	))


;; The function evalexpr outlines how to evaluate a list
;; recursively.
;;
(define (evalexpr stmt)
(let (fn (car stmt)))
(let (expr (cdr stmt)))
 (cond (
		  ((equal? fn 'dim) (dim_ expr))
		 ;((equal? fn 'let) (let_ expr))
		 ((equal? fn 'goto) (goto_ expr))
		 ;((equal? fn 'if) (if_ expr))
		 ((equal? fn 'print) (print_ expr))
		 ;((equal? fn 'input) (input_ expr))
		 ))
)
;(define if_ expre)	
;(define let_ expre)	
(define (goto_ label)
	(run((label-get! label)))
)
;(define dim expre)
(define (print expre)
	(if (string? expre)(printf expre)()
)


;;Runs the progam
(define (execute list)
	(let (line (car list)))
	(let (restOfProgram (cdr list)))
	(when (not (null? line))
		 (cond
			[((and(not (symbol? (car line)))(not(pair? line))))(execute (restOfProgram)))];;if empty statement go to restOfProgram
			[((and(symbol? (car line))(pair? (cdr line)))(evalexpr (cdr line)))];;if label- statemnt evalexpre line
			[((pair? (car line))(evalexpr (cdr ine)))];;if statement run evalexpr on line
			[(and (not(symbol? (car line)) (not(pair?(cdr line))))(execute (restOfProgram)))];;When its just a label run restOfProgram
)
)
)


(define *label-table* (make-hash))

(define (label-get key)
        (hash-reference *label-table* key))
		
(define (label-put! key value)
        (hash-set! *label-table* key value))
	
 (define (storeLabel  list)
	(when (not (null? list))
		(let ((first (caar list)))
		(when (symbol? first)
		(let ((restOfLine (cdar list))))
		(let ((nextLines (cdr list))))
		(let (restOfProg(cons restOfLine nextLines)))
			(label-put! first (restOfProg)))
		(storeLabel  (cdr list)))
 )


(define *variable-table* (make-hash))

(define (variable-get key)
        (hash-reference *variable-table* key))
		
(define (variable-put! key value)
        (hash-set! *variable-table* key value))
		
(for-each
	(lambda (pair)
		(variable-put! (car pair) (cadr pair)))
	`(
	 (e       2.718281828459045235360287471352662497757247093)
	 (pi      3.141592653589793238462643383279502884197169399)
))


(main (vector->list (current-command-line-arguments)))

