#include "queryEngine.h"

char ** query(char subject[], char predicate[], char object[])
{
	char ** triples;
	if(subject!=NULL)
		triples=solveSimpleSelectQueryCase1(subject,predicate,object);
	else if(subject==NULL && (predicate!=NULL || object!=NULL))
		triples=solveSimpleSelectQueryCase2(subject,predicate,object);
	else 
		triples=solveSimpleSelectQueryCase3(subject,predicate,object);

	return triples;
}
