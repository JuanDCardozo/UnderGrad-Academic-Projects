/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa03
 * File: dfsTrace.c
 * Purpose: 
 ****************************************************************** */
 // Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include User Lirbraries
#include "loadGraph.h"
#include "edgeList.h"
#include "intList.h"
#include "dfsTrace1.h"


/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void dfsSweepInt(int size, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent){
  int time = 0;
  for(int v = 1; size > v; ++v){
    if(color[v] == 0){
      parent[v] = -1;
      dfsTraceInt(v,adjVertices,color,dtime,ftime,parent,time);
    }
  }
}

/* Manipulation function.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void dfsTraceInt(int v, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent, int time){
  int w;
  IntList remAdj;
  
  // Set as visited and initialize variable
  color[v] = -1;
  dtime[v] = ++time;
  remAdj = adjVertices[v];

  // Traverse Linkedlist
  while(remAdj != intNil){
    w = intFirst(remAdj);
    if(color[w] == 0){
      parent[w] = v;
      dfsTraceInt(w,adjVertices,color,dtime,ftime,parent,time);
    }else{
      break;
    }
    remAdj = intRest(remAdj);
    ftime[v] = ++time;
  }//end of while

  //Set as completed
  color[v] = -2;
}

/* Procedure.
 * Preconditions: adjVertices is not intNil.
 * Postconditions: None
 */
void printDfsTrace(int size,int* color, int* dtime, int* ftime, int* parent){
  fprintf(stdout,"V color dtime ftime parent\n");
  for(int i = 1; size > i; ++i){
    fprintf(stdout,"%d %d %d %d %d\n",i,color[i],dtime[i],ftime[i],parent[i]);
    }
}

