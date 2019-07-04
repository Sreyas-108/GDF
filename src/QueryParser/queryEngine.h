#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 512

typedef enum {false=0, true=1} bool;
typedef enum tri {SUB=0, PRED=1, OBJ=2} tri;

// For '?', pass a NULL pointer


//----------
// Query is of the format <any,any,any> 
// Returns an array containing three pointers in the order subject,predicate,object
char **parseQuery(char *query);
//implemented in parser.c
//----------


//----------
//This function deletes a line from a file by creating another file with the same name 
//and same contents excluding the line given by arr, flag is used to indicate the directory
//the file is placed in.
void removeLine(char* filename, char *arr, int flag);
//implemented in removeLine.c
//----------



//----------
//Calculates md5 sum of given string
char * md5sum(char * arr);
//implemented in md5sum.c
//----------



//---------
//Deletes the tuple from the dist, resource and predicate files permanently.
void deleteTuple(char * subject, char * predicate, char * object);
//implemented in deleteTuple.c
//---------


//-----------
//changes the internal counter present at the top of all resource and predicate files.
void updateCounter(char * fileName, int flag, int toDo);
//implemented in updateCount.c
//-----------


//---------
//Creates a new tuple as well as new files for resources and predicate if required.
void insertTuple(char * subject, char * predicate, char * object);
//implemented in createTuple.c
//---------


//---------
// Returns an array of triplets of size n*3
//char **solveSimpleSelectQuery(char* subject,char* predicate,char* object);
char **solveSimpleSelectQueryCase1(char* subject,char* predicate,char* object);
char **solveSimpleSelectQueryCase2(char* subject,char* predicate,char* object);
char **solveSimpleSelectQueryCase3(char* subject,char* predicate,char* object);
//implemented in queryCase1.c, queryCase2.c, queryCase3.c
//---------


//---------
//Outermost query function which calls each select query case on the basis of
//input parameters. 
char **query(char* subject, char* predicate, char* object);
//implemented in query.c
//---------

//---------
// searches the file fp for string key (which is the md5sum of required tuple) and appends it to 
//triples at index represented by index, flag represents what is to be done to this output.
void searchAndInsert(FILE * fp, char * key, char ** triples, int index, int flag, char flagCmp[]);
//implemented in queryCase2.c
//---------

//---------
// returns a value of 1 for all strings which are not legitimate.(Contain special characters etc)
int notLegit(char* arr);
//implemented in notLegit.c
//---------
