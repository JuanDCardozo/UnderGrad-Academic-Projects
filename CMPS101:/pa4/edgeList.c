/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa3
 * File Name: edgeList.c
 * Functionaliy: Implements the ADT that is in edgeList.h 
 **************************************************************** */

// Include Standard Libraries
#include <stdlib.h>

// Include User Made Libraries
#include "edgeList.h"

// Struct for Nodes
struct EdgeListNode{
   EdgeInfo N;
   EdgeList next;
};

// Define the EdgeNil which is the empty list
const EdgeList edgeNil = NULL;


// Returns the first Edge on the list.
EdgeInfo edgeFirst(EdgeList oldL)
{
   return oldL->N;
}

// Returns the rest of the list except for the first to
EdgeList edgeRest(EdgeList oldL)
{
  return oldL->next;
}

// Creates a list
EdgeList edgeCons(EdgeInfo newL, EdgeList oldL)
{
  EdgeList new;
  new = calloc(1,sizeof(struct EdgeListNode));
  new->N.to = newL.to;
  new->N.wgt = newL.wgt;
  new->next = oldL;
  return new;
}

