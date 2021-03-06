/** ***************************************************************************
 * Name: Juan D. Cardozo
 * Student I.D: 1362585
 * CRUZ I.D: jcardozo
 * Class: CMPS 12M
 * Section: Mondays 6-8
 * Date: 05/09/2015
 * Dictionary.c
 * It implements Dictionary.h
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Dictionary.h"


// private types --------------------------------------------------------------

// NodeObj

typedef struct NodeObj {
    char* key;
    char* value;
    struct NodeObj* next;
} NodeObj;

// Node
typedef NodeObj* Node;

// newNode()
// constructor of the Node type

Node newNode(char* x, char* y)
{
    Node N = malloc(sizeof (NodeObj));
    assert(N != NULL);
    N->key = x;
    N->value = y;
    N->next = NULL;
    return (N);
}

// freeNode()
// destructor for the Node type

void freeNode(Node* pN)
{
    if (pN != NULL && *pN != NULL) {
        free(*pN);
        *pN = NULL;
    }
}

// Dictionary

typedef struct DictionaryObj {
    Node top;
    int numItems;
}DictionaryObj;


// public functions -----------------------------------------------------------

// newDictionary()
// constructor for the Dictionary type

Dictionary newDictionary(void)
{
    Dictionary D = malloc(sizeof (DictionaryObj));
    assert(D != NULL);
    D->top = NULL;
    D->numItems = 0;
    return D;
}

// freeDictionary()
// destructor for the Stack type

void freeDictionary(Dictionary* pD)
{
    if (pD != NULL && *pD != NULL) {
        if (!isEmpty(*pD)) makeEmpty(*pD);
        free(*pD);
        *pD = NULL;
    }
}

// isEmpty()
// returns 1 (true) if S is empty, 0 (false) otherwise
// pre: none

int isEmpty(Dictionary D)
{
    if (D == NULL) {
        fprintf(stderr, "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
        exit(EXIT_FAILURE);
    }
    if (D->numItems == 0) {
        return 1;
    } else {
        return 0;
    }
}

//size()

int size(Dictionary D)
{
    return D->numItems;
}

// lookup()
//returns the value v such that (k, v) is in D, or returns NULL if no 
// such value v exists.
// pre: none

char* lookup(Dictionary D, char* k)
{
  Node N = D->top;
  if(strcmp(N->key,k) == 0){
    return N->value;
  }else{
    while (N->next != NULL) {

        if (strcmp(k, N->key) == 0) {
            return N->value;
        }
        N = N->next;
    }

    return NULL;
  }
}

// insert()
// inserts key and value into D
// pre: none

void insert(Dictionary D, char* x, char* y)
{
    Node N;
    if (D == NULL) {
        fprintf(stderr, "Dictionary Error: calling insert() on NULL Dictionary reference\n");
        exit(EXIT_FAILURE);
    }else if(D->numItems == 0){
      N = newNode(x, y);
      N->next = D->top;
      D->top = N;
    }else{
      N = D->top;
      while(N->next != NULL){
	N = N->next;
      }
      N->next = newNode(x,y);
    }
    D->numItems++;
}

// delete()
// deletes pair with the key k
// pre: lookup(D, k)!=NULL

void delete(Dictionary D, char* k)
{
    Node P;
    Node garbageNode;
    if (D == NULL) {
        fprintf(stderr, "Dictionary Error: calling delete() on NULL Dictionary reference\n");
        exit(EXIT_FAILURE);
    }
    P = D->top;
    if(strcmp(P->key,k) == 0){
      garbageNode = P;
      D->top = P->next;
      D->numItems--;
    }else{
    while (strcmp(k, P->next->key) != 0) {
   	P = P->next;
    }
    garbageNode = P->next;
    P->next = P->next->next;
    D->numItems--;
    }
    freeNode(&garbageNode);

}



// makeEmpty()
// re-sets D to the empty state.
// pre: none

void makeEmpty(Dictionary D)
{
    if(D == NULL){
        fprintf(stderr, "Dictionary Error: calling makeEmpty() on NULL Dictionary reference\n");
        exit(EXIT_FAILURE);
    }
    Node G;
    Node N = D->top;
    while (N->next != NULL) {
      G = N;
      N = N->next;
        freeNode(&G);
    }
    G = N;
    freeNode(&G);
    D->numItems = 0;
    D->top = NULL;
}

// printDictionary()
// pre: none
// prints a text representation of D to the file pointed to by out

void printDictionary(FILE* out, Dictionary D)
{
    Node N;
    if (D == NULL) {
        fprintf(stderr, "Dictionary Error: calling printDictionary() on NULL Dictionary reference\n");
        exit(EXIT_FAILURE);
    }
    
    for (N = D->top; N != NULL; N = N->next) fprintf(out, "key=\"%s\" value=\"%s\"\n", N->key, N->value);
    fprintf(out,"\n");
}
