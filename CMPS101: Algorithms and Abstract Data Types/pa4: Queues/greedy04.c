/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa04
 * File Name: greedy04.c
 * Functionaliy: It reads a file with a undirected weighted graph
 * and find the shorthest path using prims and Dijktras algorithm 
 **************************************************************** */
// Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Include User Lirbraries
#include "loadWgtGraph.h"
#include "edgeList.h"
#include "minPQ.h"

// Function Prototypes
void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, int task);
void greedyTree(EdgeList* adjInfo, int n, int s,int* status, int* parent, double* fringeWgt, int task);
void printOutput(MinPQ pq, int n, int s, int task);
void calcPriority( MinPQ pq, int v, int w , double newWgt, int task);

// main
int main(int argc, char * argv[])
{
  // Declare Variables
  int size = 0;
  int task = 0;
  int s;
  // Check # Arguments for usage mistakes	
  if(argc != 4){
	  fprintf(stderr, "Usage greedy04 flag1 StartVertex Input\n");
	  exit(1);
  }

  //Specify Algorithm used
  if(strcmp("-D",argv[1]) == 0){
    task = 'D';
    printf("Algorithm Used: Dijktras Shortest Path\n"); 
  }else if(strcmp("-P",argv[1]) == 0){
    task = 'P';
    printf("Algorithm Used: Prims MST\n");
  }else{
    fprintf(stderr,"Error: Need  -D or -P\n");
    exit(1);
  }
  s =atoi(argv[2]);

  // Open File and print error if the file does not open
  FILE *input;
  input = fopen(argv[argc-1],"r");
  fprintf(stdout,"File Opened for Reading: %s\n",argv[argc-1]);
  if(input == 0){
	  fprintf(stderr,"Could not open input file\n");
	  exit(1);
  }
  
  // Get the number of vertices
  fscanf(input,"%d",&size);
  
  //Test the start vertex
  if( s > size){
    fprintf(stderr,"Error: Start Vertex >  number of vertices\n");
    exit(1);
  }

  //Close File
  fclose(input);
  printf("Number of Vertices: %d\n",size++);
  
  // Declare Adjecency array, initialize and fill it
  EdgeList* adjInfo;
  adjInfo= calloc(size,sizeof(EdgeList));
  initEdgeList(size,adjInfo);
  loadEdgeList(size,adjInfo,argv[argc-1],task);
  printEdgeList(--size,adjInfo);
  double* priority =  calloc(size+1,sizeof(double));
  for(int i = 0; size > i; ++i){
    priority[i] = HUGE_VAL;
  }
  int* parent = calloc(size+1,sizeof(int));
  int* status = calloc(size+1,sizeof(int));
  greedyTree(adjInfo, size, s, status, parent, priority,task);
  exit(0);
}

/* *****************************Implement Functions************************************* */ 
void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, int task)
{
  EdgeList remAdj;
  int status;
  remAdj = adjInfoOfV;
  while(remAdj != edgeNil){
    EdgeInfo wInfo = edgeFirst(remAdj);
    int w = wInfo.to;
    double newWgt = wInfo.wgt;
    status = getStatus(pq, w);
    if(status == UNSEEN){
      if(task == 'D'){
	newWgt += getPriority(pq,v);
      }
      insertPQ(pq,w,v, newWgt);
    }else if(status == FRINGE){
      calcPriority(pq,v,w,newWgt,task);
    }
    remAdj = edgeRest(remAdj);
  }

}

void greedyTree(EdgeList* adjInfo, int n, int s,int* status, int* parent, double* fringeWgt, int task)
{
  MinPQ pq = createPQ(n,status,fringeWgt,parent);
  insertPQ(pq,s,-1,0);
  
  while(isEmptyPQ(pq) == 0){
    int v = getMin(pq);
    delMin(pq);
    updateFringe(pq, adjInfo[v],v,task);
  }
  printOutput(pq,n,s,task);
}

void calcPriority( MinPQ pq, int v, int w , double newWgt, int task)
{
  if(task != 'D'){
    if(newWgt < getPriority(pq,w)){
      decreaseKey(pq,w,v,newWgt);
    }
  }
}

void printOutput(MinPQ pq, int n, int s,int task)
{
  int status, parent;
  double fringeWgt;
  printf("Vertices: %d\nStart Vertex: %d\n",n,s);
  if(task == 'P'){
    printf("Vertex  Status    Priority  Parent\n");
  }else{
    printf("Vertex  Status   Cost  Parent\n");
  }
  for(int i =1; n >= i; ++i){
    status = getStatus(pq,i);
    parent = getParent(pq,i);
    fringeWgt = getPriority(pq,i);
    printf("%d    %4c        %4.1lf     %4d\n",i,status,fringeWgt,parent);
  }

}
