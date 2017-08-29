/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa02
 * File: dfsTrace.h
 * Purpose: 
 ****************************************************************** */

#ifndef C101DfsTrace_H
#define C101DfsTrace_H

//User Libraries
#include "intList.h"

/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void dfsTrace(IntList *adjVertices,int* color, int* dtime, int* ftime, int*);

#endif

