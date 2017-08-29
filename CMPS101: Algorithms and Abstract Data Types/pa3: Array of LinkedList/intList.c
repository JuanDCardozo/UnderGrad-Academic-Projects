/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa3
 * File Name: intList.c
 * Functionaliy: Implements the ADT that is in intList.h 
 **************************************************************** */

// Include Standard Libraries
#include <stdlib.h>

// Include User Made Libraries
#include "intList.h"

// Struct for Nodes
struct IntListNode{
   int element;
   IntList next;
};

// Define the intNil which is the empty list
const IntList intNil = NULL;


// Returns the first int on the list.
int intFirst(IntList oldL)
{
   return oldL->element;
}

// Returns the rest of the list except for the first element
IntList intRest(IntList oldL)
{
  return oldL->next;
}

// Creates a list
IntList intCons( int newE, IntList oldL)
{
  IntList newL;
  newL = calloc(1,sizeof(struct IntListNode));
  newL->element = newE;
  newL->next = oldL;
  return newL;
}

