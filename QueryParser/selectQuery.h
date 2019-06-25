#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 512

typedef enum {false=0, true=1} bool;
typedef enum tri {SUB=0, PRED=1, OBJ=2} tri;

// For '?', pass a NULL pointer

// Query is of the format <any,any,any> 
// Returns an array containing three pointers in the order subject,predicate,object
char **parseQuery(char *query); 

// Returns an array of triplets of size n*3
//char **solveSimpleSelectQuery(char* subject,char* predicate,char* object);
char **solveSimpleSelectQueryCase1(char* subject,char* predicate,char* object);
char **solveSimpleSelectQueryCase2(char* subject,char* predicate,char* object);
char **solveSimpleSelectQueryCase3(char* subject,char* predicate,char* object);
char **query(char* subject, char* predicate, char* object);
void searchAndInsert(FILE * fp, char * key, char ** triples, int index, int flag, char flagCmp[]);
