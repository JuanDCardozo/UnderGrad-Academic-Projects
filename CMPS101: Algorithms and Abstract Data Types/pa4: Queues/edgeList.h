/********************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa4
 * File: edgeList.h
 * Purpose: This file declares the function of the edgeList ADT. In addiion,
 * it contains the information necesary for the user/cllient to be able to 
 * use the library. For instance, it explains what each function does,
 * the preconditions and postconditions.
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct
    {
    int to;
    double wgt;
    }
    EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * Preconditions: oldL is not edgeNil.
 * Postconditions: None
 */

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * Preconditions: None.
 * Postconditions: Let newL be the retturn value of edgeCons.
 * Then newL refers to a new object, newL is not edgeNil,
 * edgeFirst(newL) == newEdfeInfoElement, edgeRest(newL) == oldL.
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

