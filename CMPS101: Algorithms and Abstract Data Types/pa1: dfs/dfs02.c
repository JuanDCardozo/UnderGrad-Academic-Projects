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
	Cstring line;
	int size;
	
  // Check # Arguments for usage mistakes		
  if(argc > 4){
	  fprintf(stderr, "Error: To many arguments/nUsage dfs02 flag1 flag2 Input/n");
	  exit(1);
  }else if(argc < 2){
	  fprintf(stderr, "Error: Not enough arguments/nUsage dfs02 flag1 flag2 Input/n");
	  exit(1);
  }
  
  // Open File and print error if the file does not open
  FILE *input;
  input = fopen(argv[argc -1],"r");
  if(input == 0){
	  fprintf(stderr,"Could not open input file/n);
	  exit(1);
  }
  
  // Get the number of vertices
  fgets(line,1,input);
  size = atoi(line);
  ++size;
  Intlist adjVertices = calloc(size,sizeof(IntList);
  
  if (((argv[1] == "-u") && (argv[2] == "-w")) || ((argv[1] == "-u") && (argv[2] == "-w"))){ // Undirected and Weighted
	  printf(stderr,"Error: Weighted and Unidrected Graphs Not Supported Yet");
	  exit(1);
  }else if((argv[1] == "-w") || (argv[2] == "-w")){ // Directed weighted
	  printf(stderr,"Error: Weighted Graphs Not Supported Yet");
	  exit(1);
  }else if ( (argv[1] == "-u")|| (argv[2] == "-u")){ // Undirected weighted
	  printf(stderr,"Error: Undirected Graphs Not Supported Yet");
	  exit(1);
  }else{ // Directed unweighted graph
	  
	  //Initializes Array to intNil
	  initList(size,adjVertices);
	  
	  //Fill array with Edges
	  loadList(size, adjVertices);
  }
  
  //Print Array
  /*
  for(int i = 1; size > i;++i){
	  while((adjVerrtices+i) != intNil){
		  fprintf(stdout,")
	  }
  }
  */
  
  //Deep First Search Trace
  
  
  //Print Deep First Trace Info
  
  
  //Print
  fclose(input);
  exit(0);
  }

 



