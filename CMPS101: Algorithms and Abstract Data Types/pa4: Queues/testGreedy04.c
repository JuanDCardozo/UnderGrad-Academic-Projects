/* ******************************************************************
 * Name: Juan D. Cardozo
 * Cruz I.D: jcardozo
 * Student I.D: 1362585
 * Assigment: pa04
 * File: testGreedy04
 * Purpose: 
 ****************************************************************** */
// Include User Libraries to Test
#include "loadWgtGraph.h"
#include "edgeList.h"
#include "minPQ.h"

// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  /************************** Variables******************************* */
  // Test Counters
  int testsPassed = 0;
  int modulePassed = 0;
  int functionPassed = 0;
   
  // edgeList test variables
  EdgeInfo tempEdge;
  EdgeList edgeArray[3];
  for(int i = 0; 3 > i; ++i){
    edgeArray[i] = edgeNil;
  }
  EdgeList restEdgeList;
  restEdgeList = edgeNil;

  // loadWgtGraph test variables
  EdgeList* adjEdgeList = calloc(6,sizeof(EdgeList));

  // minPQ test variables
  int pqSize = 3;
  int* status = calloc(pqSize+1,sizeof(int));
  int* parent = calloc(pqSize+1,sizeof(int));
  double* priority = calloc(pqSize+1,sizeof(double));
  MinPQ tempPQ;

  /******************************************************************** */

  // Check input
  if(argc != 2){
	  fprintf(stderr, "Error: Usage test test1\n");
	  exit(1);
  }
  printf("_________________________\n"
	 "\nTest File:%s\n"
	 "-------------------------\n",argv[argc-1]);

  /* ************** edgeList Module Test***************************** */
   
  //-----------------------------------------------------
  // edgeCons()
  //-----------------------------------------------------
  tempEdge.to = 1;
  tempEdge.wgt = 1.1;
  edgeArray[0] = edgeCons(tempEdge, edgeArray[0]);
  tempEdge.to = 2;
  tempEdge.wgt = 2.2;
  edgeArray[1] = edgeCons(tempEdge, edgeArray[1]);
  tempEdge.to = 3;
  tempEdge.wgt = 3.3;
  edgeArray[1] = edgeCons(tempEdge, edgeArray[1]);
  tempEdge.to = 4;
  tempEdge.wgt = 4.4;
  edgeArray[2] = edgeCons(tempEdge, edgeArray[2]);
  tempEdge.to = 5;
  tempEdge.wgt = 5.5;
  edgeArray[2] = edgeCons(tempEdge, edgeArray[2]);

  for(int i = 0; 3 > i; ++i){
    if(edgeArray[i] != edgeNil){
      ++functionPassed;
    }
  }
  if(functionPassed == 3){
    ++testsPassed;
  }
  functionPassed = 0;

  //-----------------------------------------------------
  // edgeFirst()
  //-----------------------------------------------------
  tempEdge = edgeFirst(edgeArray[0]);
  if((tempEdge.to == 1)&& (tempEdge.wgt == 1.1 )){
    ++functionPassed;
  }
  tempEdge = edgeFirst(edgeArray[1]);
  if((tempEdge.to == 3)&& (tempEdge.wgt == 3.3 )){
    ++functionPassed;
  }
  tempEdge = edgeFirst(edgeArray[2]);
  if((tempEdge.to == 5)&& (tempEdge.wgt == 5.5 )){
    ++functionPassed;
  }
  if(functionPassed == 3){
    ++testsPassed;
  }
  functionPassed = 0;
  //----------------------------------------------------
  // edgeRest()
  //-----------------------------------------------------
  tempEdge.to = 6;
  tempEdge.wgt = 6.6;
  edgeArray[0] = edgeCons(tempEdge, edgeArray[0]);
  restEdgeList = edgeRest(edgeArray[0]);
  tempEdge  = edgeFirst(restEdgeList);
  if((tempEdge.to == 1 )&& (tempEdge.wgt == 1.1 )){
    ++functionPassed;
  }
  restEdgeList = edgeRest(edgeArray[1]);
  tempEdge  = edgeFirst(restEdgeList);
  if((tempEdge.to == 2 )&& (tempEdge.wgt == 2.2 )){
    ++functionPassed;
  }
  restEdgeList = edgeRest(edgeArray[2]);
  tempEdge  = edgeFirst(restEdgeList);
  if((tempEdge.to == 4 )&& (tempEdge.wgt == 4.4 )){
    ++functionPassed;
  }
  if(functionPassed == 3){
    ++testsPassed;
  }
  functionPassed = 0;

  //------------------------------------------------
  // edgeList Module Test Results
  //------------------------------------------------

  if(testsPassed == 3){
    ++modulePassed;
    printf("edgeList Module Test: PASSED\n"
	   "----------------------------\n");
  }else{
    printf("edgeList Module Test: FAILLED\n"
	   "-----------------------------\n");

    // Find Functions that FAILED
    if(testsPassed == 0){
      printf("Errors in:\n-edgeCons()\n-edgeFirst()\n-edgeRest()\n");
	}else if(testsPassed == 1){
      printf("Errors in:\n-edgeFirst()\n-edgeRest()\n");
	}else if(testsPassed == 2){
      printf("Errors in:\n-edgeRest()\n");
	}

  }
  //Reset modulePassed Variable
  testsPassed = 0;

  /* ************************** loadWgtGraph Module Test********** */

  //-----------------------------------------------------
  // initEdgeList()
  //-----------------------------------------------------
  initEdgeList(5,adjEdgeList);
  for(int i = 1; 5 >= i; ++i){
    if(adjEdgeList[i] == edgeNil){
      ++functionPassed;
    }
  }
  if(functionPassed == 5){
    ++testsPassed;
  }
  functionPassed = 0;
  //-----------------------------------------------------
  // loadEdgeList()
  //-----------------------------------------------------
  loadEdgeList(5,adjEdgeList,argv[argc-1],'P');

  tempEdge = edgeFirst(adjEdgeList[1]);
  if((tempEdge.to == 4 )&& (tempEdge.wgt == 5.2 )){
    ++functionPassed;
  }
  restEdgeList = edgeRest(adjEdgeList[1]);
  tempEdge = edgeFirst(restEdgeList);
  if((tempEdge.to == 3)&& (tempEdge.wgt == 2.2 )){
    ++functionPassed;
  }
  tempEdge = edgeFirst(adjEdgeList[2]);
  if((tempEdge.to == 4 )&& (tempEdge.wgt == 5.5 )){
    ++functionPassed;
  }
  tempEdge = edgeFirst(adjEdgeList[3]);
  if((tempEdge.to == 4 )&& (tempEdge.wgt == 5.3 )){
    ++functionPassed;
  }
  tempEdge = edgeFirst(adjEdgeList[4]);
  if((tempEdge.to == 5)&& (tempEdge.wgt == 5.8)){
    ++functionPassed;
  }

  restEdgeList = edgeRest(adjEdgeList[4]);
  tempEdge = edgeFirst(restEdgeList);
  if((tempEdge.to == 3 )&& (tempEdge.wgt == 5.3)){
    ++functionPassed;
  }
  tempEdge = edgeFirst(adjEdgeList[5]);
  if((tempEdge.to == 4 )&& (tempEdge.wgt == 5.8 )){
    ++functionPassed;
  }
   if(functionPassed == 7){
    ++testsPassed;
  }
  functionPassed = 0;
  //----------------------------------------------------
  // printEdgeList()
  //-----------------------------------------------------
   printf("\nprintEddgeList() Output:\n");
   printEdgeList(5, adjEdgeList);
   ++testsPassed;
  //------------------------------------------------
  // loadWgtGraph Module Test Results
  //------------------------------------------------
  if(testsPassed == 3){
    ++modulePassed;
    printf("\nloadWgtGraph Module Test: PASSED\n"
	   "-------------------------------\n");
  }else{
    printf("\nloadWgtGraph Module Test: FAILLED\n"
	   "--------------------------------\n");
  }
  //Reset modulePassed Variable
  testsPassed = 0;

  /* ************************** minPQ Module Test********** */

  //-------------------------------------------------------
  // createPQ()
  //-------------------------------------------------------
  tempPQ = createPQ(pqSize,status,priority,parent);
  //--------------------------------------------------------
  // insert()and isEmpty()
  //--------------------------------------------------------
  int emptyN = isEmptyPQ(tempPQ);  
  if(emptyN == 1){
    ++functionPassed;
  }
  insertPQ(tempPQ,1,2,1.1);
  emptyN = isEmptyPQ(tempPQ);
  if(emptyN == 0){
      ++functionPassed;
   }
  if(functionPassed == 2){
    ++testsPassed;
  }
  functionPassed = 0;
  //--------------------------------------------------------
  // getMin()
  //--------------------------------------------------------
  insertPQ(tempPQ,2,3,2.2);
  insertPQ(tempPQ,3,1,3.3);
  int min = getMin(tempPQ);
  if(min == 2.2){
    ++testsPassed;
  }
  //--------------------------------------------------------
  // getPriority()
  //--------------------------------------------------------
  int priorityN = getPriority(tempPQ,1);
  if(priorityN == 1.1){
    ++functionPassed;
  }
  priorityN = getPriority(tempPQ,2);
  if(priorityN == 2.2){
    ++functionPassed;
  }
  priorityN = getPriority(tempPQ,3);
  if(priorityN == 3.3){
    ++functionPassed;
  }
  if(functionPassed == 3){
    ++testsPassed;
  }
  functionPassed = 0;
  //--------------------------------------------------------
  // getStatus()
  //--------------------------------------------------------
  int statusN = getStatus(tempPQ,1);
  if(statusN == 1.1){
      ++testsPassed;
  }
  //--------------------------------------------------------
  // getParent()
  //--------------------------------------------------------
  int parentN = getParent(tempPQ,1);
  if(parentN == 2){
    ++functionPassed;
  }
  parentN = getParent(tempPQ,2);
  if(parentN == 3){
    ++functionPassed;
  }
  parentN = getParent(tempPQ,3);
  if(parentN == 1){
    ++functionPassed;
  }
  if(functionPassed == 3){
    ++testsPassed;
  }
  //--------------------------------------------------------
  // decreaseKey()
  //--------------------------------------------------------
  decreaseKey(tempPQ,1,3,2.2);
  priorityN= getPriority(tempPQ,1);
  if(priorityN == 2.2){
    ++functionPassed;
  }
  decreaseKey(tempPQ,2,3,1.1);
  priorityN = getPriority(tempPQ,2);
  if(priorityN == 1.1){
    ++functionPassed;
  }
  decreaseKey(tempPQ,3,2,1.2);
  priorityN = getPriority(tempPQ,3);
  if(priorityN == 1.2){
    ++functionPassed;
  }
  if(functionPassed == 3){
    ++testsPassed;
  }
  //--------------------------------------------------------
  // minPQ Module Test Results
  //------------------------------------------------------- 
  if(testsPassed == 3){
    ++modulePassed;
    printf("minPQ Module Test: PASSED\n");
  }else{
    printf("minPQ Module Test: FAILLED\n");
  }

  //Reset modulePassed Variable
  testsPassed = 0;

  /* ************************ Program Test Result******************************* */

  if(modulePassed == 3){
    printf("__________________________\nProgram Test: PASSED\n__________________________\n");
  }else{
    printf("__________________________\nProgram Test: FAILLED\n-Completed: %d of 3\n__________________________\n",modulePassed);
  }
exit(0);
}
