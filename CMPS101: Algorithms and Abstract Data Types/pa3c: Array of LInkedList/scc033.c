/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa2
 * File Name: dfs02.c
 * Functionaliy: It reads a file and creates its adjecency list,
 * and then prints it out. 
 **************************************************************** */
// Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include User Lirbraries
#include "loadGraph.h"
#include "edgeList.h"
#include "intList.h"
#include "dfsTrace1.h"

// Typedef and structs
typedef char* Cstring;

// Function Prototypes
IntList* transposeGraph(IntList* origGraph, int n);

// main
int main(int argc, char * argv[])
{
	// Declare Variables
	Cstring line = NULL;
	int size = 0;
	int time = 0;

  // Check # Arguments for usage mistakes	
  if(argc > 4){
	  fprintf(stderr, "Error: To many arguments\nUsage dfs02 flag1 flag2 Input\n");
	  exit(1);
  }else if(argc < 2){
	  fprintf(stderr, "Error: Not enough arguments\nUsage dfs02 flag1 flag2 Input\n");
	  exit(1);
  }
  // Open File and print error if the file does not open
  FILE *input;
  input = fopen(argv[argc-1],"r");
  fprintf(stdout,"File Opened for Reading: %s\n",argv[argc-1]);
  if(input == 0){
	  fprintf(stderr,"Could not open input file\n");
	  exit(1);
  }
  
  // Get the number of vertices
  fgets(line,1,input);
  size = atoi(line);
  
  //Close File
  fclose(input);
  printf("Number of Vertices: %d\n",size++);

  // Allocate Important Arrays 
  int* color = calloc(size,sizeof(int));
  int* dtime = calloc(size,sizeof(int));
  int* ftime = calloc(size,sizeof(int));
  int* parent = calloc(size,sizeof(int));
  
  // Select the graph that goes with the flags in the command line
  if (((strcmp(argv[1],"-u") == 0) && (strcmp(argv[2],"-w") == 0)) ||(strcmp(argv[1],"-w") == 0 && (strcmp(argv[2],"-u") == 0))){ // Undirected and Weighted
  
	  // Print Error
	  fprintf(stderr,"Error: Weighted and Unidrected Graphs Not Supported Yet\n");
	  exit(1);
	  
    }else if(((strcmp(argv[1],"-w")== 0) || ((strcmp(argv[2],"-w")== 0)))){ // Directed weighted
	
	  // Allocate Array
	  EdgeList* adjVertices = calloc(size,sizeof(IntList));
	
	  //Initializes Array to intNil
	  initEdgeList(size,adjVertices);
	  
	  //Fill array with Edges
	  loadEdgeList(size, adjVertices, argv[argc-1]);
	  
	  // Print IntList
	  printEdgeList(size, adjVertices);
	  
	}else if (((strcmp(argv[1],"-u")== 0) || ((strcmp(argv[2],"-u")== 0)))){ // Undirected weighted
	  
	  //Print Error
	  fprintf(stderr,"Error: Undirected Graphs Not Supported Yet\n");
	  exit(1);
	  
  }else{ // Directed unweighted graph
  
	   // Allocate Array
	   IntList* adjVertices = calloc(size,sizeof(IntList));
		
	  //Initializes Array to intNil
	   initIntList(size,adjVertices);
	  
	  //Fill array with Edges
	   loadIntList(size, adjVertices, argv[argc-1]);
	  
	  // Print IntList
	  printIntList(size, adjVertices);
	  
	  //Deep First Search Trace
	  dfsSweepInt(size, adjVertices,color, dtime, ftime, parent);
  }
 
  exit(0);
  }

/* *****************************Implement Functions************************************* */ 
IntList* transposeGraph(IntList* origGraph, int size)
{
  int from = 0;
  IntList* newGraph = calloc(size,sizeof(IntList));
  IntList next;
  for(int i = 1; size > i; ++i){
    next = origGraph[i];
    while(next != intNil){
      from = intFirst(next);
      newGraph[from] = intCons(i, newGraph[from]);
      next = intRest(next);
    }
  }
  return newGraph;
}


