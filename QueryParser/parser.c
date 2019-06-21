#include "Parser.h"

char ** parseQuery(char * query)
{
		int i=0;
		int j=0;
		char ** triples;

		triples=(char **) malloc(sizeof(char *)*3);
		
		for(int k=0;k<=2;k++)
		{
				triples[k]=(char *)malloc(sizeof(char)*10);
		}
		int size=0,ini=10;
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
							size++;
							if(size>10)
							{
									ini*=2;
									triples[j]=(char *)realloc(triples[j],sizeof(char)*ini);
							}
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
