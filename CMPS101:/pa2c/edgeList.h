/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa2
 * File Name: edgeList.h
 * Functionaliy: Implements the ADT that is in edgeList.h 
 **************************************************************** */

#ifndef CS101EdgeList_H
#define CS101EdgeList_H

typedef struct EdgeListNode * EdgeList;

// EdgeInfo Struct
typedef struct EdgeInfo{
   int to;
   double wgt;
}EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions.
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
 * Postconditions: Let newL be the return value of of edgeCons.
 * Then newL refers to a new object, newL is not edgeNil,
 * edgeFirst(newL) == newElement, rest(newL) == oldL
 */

/** cons
 */
EdgeList edgeCons(int newTo,double newWgt, EdgeList oldL);

#endif
