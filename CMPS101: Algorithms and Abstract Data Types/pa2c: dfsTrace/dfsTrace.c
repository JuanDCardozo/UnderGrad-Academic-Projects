/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa02
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
#include "dfsTrace.h"

#define white 0
#define gray -1
#define black -2
/*
void dfsSweep(int size, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent){
  time = 0;
  for(int v = 1; size > v; ++v){
    if(color[v] == white){
      parent[v] = -1;
      dfsTrace(v,adjVertices,color,dtime,ftime,parent,time);
    }
  }
}

void dfsTraceInt(int v, IntList* adjVertices,int* color, int* dtime, int* ftime, int* parent, int time){
  int w;
  IntList remAdj;
  
  // Set as visited and initialize variable
  color[v] = gray;
  dtime[v] = ++time;
  remAdj = adjVertices[v];

  // Traverse Linkedlist
  while(remAdj != intNil){
    w = intFrist(remAdj);
    if(color[w] == white){
      parent[w] = v;
      dfsTrace(w,adjVertices,color,dtime,ftime,parent,time);
    }else{
      break;
    }
    remAdj = intRest(remAdj);
    ftime[v] = ++time;
  }//end of while

  //Set as completed
  color[v] = black;
}

void printDfsTrace(int size,int* color, int* dtime, int* ftime, int* parent){
  fprintf(stdout,"V color dtime ftime parent\n"
  for(int i = 1; size > i; ++i){
    fprintf(stdout,"%d %d %d %d %d\n",i,color[i],dtime[i],ftime[i],parent[i]);
    }
}
*/
