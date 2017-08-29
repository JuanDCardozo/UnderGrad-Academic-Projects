/** ***************************************************************************
 * Name: Juan D. Cardozo
 * Student I.D: 1362585
 * CRUZ I.D: jcardozo
 * Class: CMPS 12B
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

//Hash Functions and variables-------------------------------------------------

// Size of Hash table
const int tableSize = 101;

// Hash Functions
// rotate_left()
// rotate the bits in an unsigned int
unsigned int rotate_left(unsigned int value, int shift) {
	int sizeInBits = 8*sizeof(unsigned int);
	shift = shift & (sizeInBits - 1);
	if ( shift == 0 )
		return value;
	      return (value << shift) | (value >> (sizeInBits - shift));
}

// pre_hash()
// turn a string into an unsigned int
unsigned int pre_hash(char* input) {
	unsigned int result = 0xBAE86554;
	while (*input) {
		result ^= *input++;
		result = rotate_left(result, 5);
	}
	return result;
}

// hash()
// turns a string into an int in the range 0 to tableSize-1
int hash(char* key){
	return pre_hash(key)%tableSize;
}

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
    Node* table;
    int numItems;
}DictionaryObj;


// newDictionary()
// constructor for the Dictionary type
Dictionary newDictionary(void)
{
  Dictionary D = malloc(sizeof(DictionaryObj));
  D->table = calloc(tableSize,sizeof(Node));
  D-> numItems = 0;
	return D;
}

// freeDictionary()
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD)
{
	 if (pD != NULL && *pD != NULL) {
        if (!isEmpty(*pD)) makeEmpty(*pD);
	free((*pD)->table);
        free(*pD);
        *pD = NULL;
    }
}
	

// isEmpty()
// returns 1 (true) if S is empty, 0 (false) otherwise
// pre: none
int isEmpty(Dictionary D)
{
	return (D->numItems == 0)? 1:0;
}

// size()
// returns the number of (key, value) pairs in D
// pre: none
int size(Dictionary D)
{
	return (D->numItems);
}

// lookup()
// returns the value v such that (k, v) is in D, or returns NULL if no 
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k)
{
	int  index = hash(k);
	Node N = D->table[index];
	if(N == NULL){
		return NULL;
	}else if(N->next == NULL){
		return N->value;
	}else{ // N->next != NULL
		while(strcmp(k,N->key) != 0){
			N = N->next;
		}
		return N->value;
	}
}

// insert()
// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* k, char* v)
{
  if (lookup(D,k) != NULL) {
        fprintf(stderr, "Dictionary Error: cannot insert dublicate of keys\n");
        exit(EXIT_FAILURE);
    }
	int index = hash(k);
	Node N = D->table[index];
	if(N == NULL){
	        D->table[index] = newNode(k,v);
	}else{ // N->next != NULL
		while(N->next != NULL){
			N = N->next;
		}
		N = newNode(k,v);
		N->next = D->table[index];
		D->table[index] = N;
	}
	D->numItems++;
}

// delete()
// deletes pair with the key k
// pre: lookup(D, k)!=NULL
void delete(Dictionary D, char* k)
{
	if (lookup(D, k) ==NULL) {
        fprintf(stderr, "Dictionary Error: calling delete() on Non-Existent key\n");
        exit(EXIT_FAILURE);
    }
	int index = hash(k);
	Node N = D->table[index];
	if(N->next == NULL){
	  freeNode(&N);
	  D->table[index] = NULL;
	}else{ // N->next != NULL
		while(strcmp(k,N->key) != 0){
			N = N->next;
		}
		Node G = N->next;
		N->next = N->next->next;
		freeNode(&G);
	}
	D->numItems--;
}

// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D)
{
  Node N;
  Node G;
   for(int i = 0; i < tableSize; i++){
     N = D->table[i];
     while(N != NULL){
       G = N;
       N = N->next;
       freeNode(&G);
     }
     if(D->table[i] != NULL){
       D->table[i] = NULL;
     }
   }
   D->numItems = 0;
}

// printDictionary()
// pre: none
// prints a text representation of D to the file pointed to by out
void printDictionary(FILE* out, Dictionary D)
{
  Node N;
	for(int i = 0; i < tableSize; i++){
	  if(D->table[i] != NULL){
	    N = D->table[i];
	    while(N != NULL){
		fprintf(out, "%s %s\n", N->key, N->value);
		N = N->next;
	    }
	  }	
	
	}

}
