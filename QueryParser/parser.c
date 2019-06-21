#include "selectQuery.h"

char ** parseQuery(char * query)
{
	int i=0;
	int j=0;
	char ** triples;

	triples=(char **) malloc(sizeof(char *)*3);

	for(int k=0;k<=2;k++)
	{
		triples[k]=(char *)malloc(sizeof(char)*	MAX);
	}
	int k=0;
	while(query[i]!='>')
	{
		k=0;
		if(query[i]=='<')
			i++;
		while(query[i]!=',' && query[i]!='>')
		{
			if(query[i]=='?')
			{
				triples[j]=NULL;
			}
			else
			{
				triples[j][k]=query[i];
				k++;
			}
			i++;
		}
		if(triples[j]!=NULL)
		{
			triples[j][k]='\0';
		}
		if(query[i]=='>')
			break;
		j++;
		i++;
	}
	return triples;
}
