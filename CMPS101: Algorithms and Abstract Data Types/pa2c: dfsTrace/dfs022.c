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
#include "dfsTrace.h"

// Typedef and structs
typedef char* Cstring;


// main
int main(int argc, char * argv[])
{
	Cstring line = NULL;
	int size;
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
  fprintf(stderr,"File Opened for Reading: %s\n",argv[argc-1]);
  if(input == 0){
	  fprintf(stderr,"Could not open input file\n");
	  exit(1);
  }
  
  // Get the number of vertices
  fgets(line,1,input);
  size = atoi(line);
  ++size;
  printf("Number of Vertices: %d\n",size);
  IntList adjVertices;// = calloc(size,sizeof(IntList));
  printf("Before checking what kind of graph");
  if (((strcmp(argv[1],"-u") == 0) && (strcmp(argv[2],"-w") == 0)) ||(strcmp(argv[1],"-w") == 0 && (strcmp(argv[2],"-u") == 0))){ // Undirected and Weighted
	  fprintf(stderr,"Error: Weighted and Unidrected Graphs Not Supported Yet\n");
	  exit(1);
    }else if(((strcmp(argv[1],"-w")== 0) || ((strcmp(argv[2],"-w")== 0)))){ // Directed weighted
	  fprintf(stderr,"Error: Weighted Graphs Not Supported Yet\n");
	  exit(1);
	  }else if (((strcmp(argv[1],"-u")== 0) || ((strcmp(argv[2],"-u")== 0)))){ // Undirected weighted
	  fprintf(stderr,"Error: Undirected Graphs Not Supported Yet\n");
	  exit(1);
  }else{ // Directed unweighted graph
    printf("Entered Else\n");
	  //Initializes Array to intNil
    // initList(size,adjVertices);
	  
	  //Fill array with Edges
	  //  loadList(size, adjVertices);
  }
			       /*
  //Print Array
  for(int i = 1; size > i;++i){
	  while((adjVerrtices+i) != intNil){
	    fprintf(stdout,"%d [%d ",i,adjVertices->element)
	  }
  }
			       */
  
  //Deep First Search Trace
  
  
  //Print Deep First Trace Info
  
  
  //Print
  fclose(input);
  exit(0);
  }

 



