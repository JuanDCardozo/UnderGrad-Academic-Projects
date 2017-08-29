/* *****************************************************************
 * Name: Juan D. Cardozo
 * cruz Id: jcardozo
 * studnet Id:1362585
 * Assignment pa4
 * File: minPQ.h
 * Purpose This file declares all the functions that are implemented
 * in minPQ.c. It is an ADT that creates a priority queue to keep track
 * of the updated paths to edges and use it in prims and dijkstras algorithms
*/

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* Access functions
 * Preconditions: Queue exists and the address is not NULL;
 * Postcondition: None.
*/

/** isEmpty
*/
int isEmptyPQ(MinPQ pq);

/** getMin
*/
int getMin(MinPQ pq);

/** getStatus
*/
int getStatus(MinPQ pq, int id);

/** getParent
*/
int getParent(MinPQ pq, int id);

/** getPriority
*/
double getPriority(MinPQ pq, int id);

/* Manipulation procedures
 * Preconditions: Queue exists and the address is not NUll
 * Postconditions: Queue exists and the address is not NUll
*/

/** delMin
*/
void delMin(MinPQ pq);

/** insertPQ
*/
void insertPQ(MinPQ pq, int id, int par, double priority);

/** decreaseKey
*/
void decreaseKey(MinPQ pq, int id, int par, double priority);

/* Constructors
 * Preconditions: None.
 * Postconditions: Let newPQ be the return value of createPQ
 * Then newPQ refers to a new object
*/

/**
*/
MinPQ createPQ(int n, int status[], double priority[], int parent[]);


#endif

