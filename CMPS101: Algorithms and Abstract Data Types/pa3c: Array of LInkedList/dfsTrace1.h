/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa03
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
void dfsSweepInt(int size, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent);

/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void dfsTraceInt(int v, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent, int time);

/* Procedure.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void printDfsTrace(int size,int* color, int* dtime, int* ftime, int* parent);

void printDfsPhase(int size, int* dtime, int* ftime, int* parent,int* dfsRoot);

#endif

