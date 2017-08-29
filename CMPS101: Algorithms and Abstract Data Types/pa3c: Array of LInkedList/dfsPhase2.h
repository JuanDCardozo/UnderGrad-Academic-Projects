/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa3
 * File Name: dfsPhase2.h
 * Functionaliy: It reads a file and creates its adjecency list,
 * and then prints it out. 
 **************************************************************** */
 
#ifndef C101DfsPhase2_H
#define C101DfsPhase2_H

// Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//User Libraries
#include "intList.h"

/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void dfsSweepIntT(int size, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent);

/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void dfsTraceIntT(int v, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent, int time);


/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
 void dfsPhase2(int v, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent, int time);

#endif
