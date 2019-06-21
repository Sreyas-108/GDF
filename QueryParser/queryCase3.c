#include "Parser.h"
#define MAX 512
typedef enum tri {SUB=0, PRED=1, OBJ=2} tri;


//Case 3
//<?,?,?>
char ** solveSimpleSelectQueryCase3(char* subject,char* predicate,char* object)
{
	FILE * fp=fopen("distribution.gdf","r");

	char ** triples;
	int counter=0;
	int size=100;
	int j=0;

	triples=(char **)malloc(sizeof(char *)*size);
	
	char * spl[7];

	if(subject==NULL && predicate==NULL && object==NULL)
	{
		char * readWhole=(char *)malloc(sizeof(char)*MAX*7);
		
		for(int i=0;i<7;i++)
		{
			spl[i]=(char *)malloc(sizeof(char)*MAX);
		}

		while(fscanf(fp,"%[^\n]\n",readWhole)!=EOF)
		{
			char * copy=(char *)malloc(sizeof(char)*7*MAX);
			strcpy(copy,readWhole);
			for(int i=0;i<7;i++)
			{
				strcpy(spl[i],strsep(&copy,"|"));
			}
			
			int tmp=0;
			for(int i=0;i<7;i++)
			{
				tmp+=strlen(spl[i]);
			}
			tmp+=7;

			if(counter>size)
			{
				size*=2;
				triples=(char **)realloc(triples,sizeof(char *)*size);
			}
			
			triples[j]=(char *)malloc(sizeof(char)*tmp);

			for(int i=0;i<7;i++)
			{
				strcat(triples[j],spl[i]);
				if(i!=6)
					strcat(triples[j],"|\0");
			}	
			counter++;
			j++;
		}
	}
}
