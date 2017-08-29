/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa1
 * File: intList.h
 * Purpose: This file declares the functions of the ADT. In addition,
 * it contains the information necesarry for the user/client to be able
 * to use this library. For instance, it explains what each function does,
 * the preconditionds and postconditions.
 ****************************************************************** */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions.
 * Preconditions: oldL is not intNil.
 * Postconditions: None
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

/* Constructors
 * Preconditions: None.
 * Postconditions: Let newL be the return value of of intCons.
 * Then newL refers to a new object, newL is not intNil,
 * intFirst(newL) == newElement, rest(newL) == oldL
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

