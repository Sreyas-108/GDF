#include "selectQuery.h"

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

char * lower(char* str)
{
	int len=strlen(str);
	char * newStr=(char *)malloc(sizeof(char)*(len+1));
	strcpy(newStr,str);
	strcat(newStr,"\0");
	for(int i=0;i<len;i++)
	{
		newStr[i]=tolower(newStr[i]);
	}
	return newStr;
}
