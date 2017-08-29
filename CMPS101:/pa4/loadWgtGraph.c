/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa1
 * File: loadGraph.c
 * Purpose: 
 ****************************************************************** */

 // Include Standard Libraries
#include <stdlib.h>

// Include User Made Libraries
#include "loadWgtGraph.h"
#include "edgeList.h"


typedef struct{
  int from;
  int to;
  double weight;
}Edge;

/* *****************************Private Functions********************* */

Edge parseEdge(char line[])
{
	Edge newE;
	int numFields;
	numFields = sscanf(line, " %d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
	if (numFields < 2 || numFields > 3){
		fprintf(stderr,"Bad edge:  %s", line);
		exit(1);
	}

	if (numFields == 2){
		newE.weight = 0.0;
	}
	return newE;
}

/* *****************************Public Functions********************* */

 /* Manipulation function.
 * Preconditions: None
 * Postconditions: None
 */
 void initEdgeList(int size, EdgeList* adjVertices)
{
	for(int i = 0; size >= i; ++i){		 
		  adjVertices[i] = edgeNil;
	 }
}

/* Manipulation function.
 * Preconditions: adjVertices is not intNil and size bigger than 1.
 * Postconditions: None
 */
void loadEdgeList(int size, EdgeList* adjVertices, char* file, int task)
 {
	char line[1024];
	char* fgetsRetn;
	EdgeInfo newL;

	//Open file to read from 
	FILE* input;
	input = fopen(file,"r");

	//Check if the file was opened	 
	if(input == NULL){
		fprintf(stderr,"Error: File %s could not be opened/n", file);
		exit(1);
	}
	
	//Prints message to inform current file
	fprintf(stdin,"File %s opened to be read/n",file);
	
	//Read Input and
	fgetsRetn = fgets(line, 1024, input);
	fgetsRetn = fgets(line, 1024, input);
	while (fgetsRetn == line){
		Edge e = parseEdge(line);
		newL.to = e.to;
		newL.wgt = e.weight;
		adjVertices[e.from] = edgeCons(newL, adjVertices[e.from]);
		newL.to = e.from;
		newL.wgt = e.weight;
		if( task == 'P'){
		  adjVertices[e.to] = edgeCons(newL, adjVertices[e.to]);
		}
		fgetsRetn = fgets(line, 1024, input);
	}
	
	//Close file
	fclose(input);

 }

/* Procedure.
 * Preconditions: adjVertices is not edgeNil and size bigger than 1.
 * Postconditions: None
 */

void printEdgeList(int size, EdgeList* adjVertices)
{
  EdgeList next;
  EdgeInfo element;
  
  //Go through all the vertices
    for(int i = 1;size >= i;++i){
      next = adjVertices[i];
      fprintf(stdout,"%d [",i);

      // Print all the edges from this Vertex
      while(next != edgeNil){
	element = edgeFirst(next);
	fprintf(stdout," %d@%.1lf",element.to, element.wgt); 
	next = edgeRest(next);
	if(next != edgeNil){printf(",");}
      }
      
      // Print End of set of edges
      fprintf(stdout,"]\n");
    }
}

