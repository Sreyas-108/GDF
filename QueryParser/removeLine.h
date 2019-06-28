#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 512

void removeLine(char* filename, FILE* ptr);
char * md5sum(char * arr);
void deleteTuple(char * subject, char * predicate, char * object);
