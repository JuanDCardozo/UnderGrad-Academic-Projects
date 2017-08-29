/* ***************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assignment: pa1
 * File Name: graph01.c
 * Functionaliy: It reads a file and creates its adjecency list,
 * and then prints it out. 
 **************************************************************** */
// Include Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include User Lirbraries
#include "intList.h"

// Typedef and structs
typedef char* Cstring;

typedef struct{
  int from;
  int to;
  double weight;
}Edge;

// Function Prototypes
Edge parseEdge(char line[]);

// main
int main(int argc, char * argv[])
{
  FILE *inbuf = fopen(argv[1],"r");
  printf("Opened %s to extract data\n", argv[1]);
  char line[1024];
  Cstring fgetsRetn;
  IntList adjVertices[1024] = {intNil};
  Edge e;

  // Read Lines and put into LinkedList
  fgetsRetn = fgets(line, 1024, inbuf);
  while(fgetsRetn == line){
    e = parseEdge(line);
    adjVertices[e.from] = intCons(e.to,adjVertices[e.from]);
    fgetsRetn = fgets(line,1024, inbuf); 
  }
  if(!feof(inbuf)){
    printf("Error feof not found");
    exit(1);
  }

  // Prints out the adjecency List
  int i = 1;
  printf("[");
  while(intRest(adjVertices[i]) != intNil){
    printf("%d",i);
    while(intRest(adjVertices[i]) != intNil){
      printf(", %d",intFirst(adjVertices[i]));
    }
    printf("]/n");
  }
  fclose(inbuf);
  exit(0);
}


// Function Implementation
// parseEdge extracts data items from the char array.
Edge parseEdge(char line[])
{
  Edge newE;
  int numFields;
  numFields = sscanf(line, " %d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
  if(numFields == 2){
    newE.weight = 0.0;
    return newE;
  }
  printf("Bad edge: %s", line);
  exit(1);
}
