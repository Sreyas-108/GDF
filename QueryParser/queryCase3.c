#include "selectQuery.h"

//Case 3
//<?,?,?>

char ** solveSimpleSelectQueryCase3(char* subject,char* predicate,char* object)
{

	FILE * fp=fopen("/dist.gdf","r");
	if(fp==NULL)
	{
		printf("ERROR!! The dist.gdf file is missing");
		exit(0);
	}
	//printf("%p\n",fp);

	char ** triples;
	int counter=0;
	int size=1;
	int j=0;

	triples=(char **)malloc(sizeof(char *)*size);

	if(subject==NULL && predicate==NULL && object==NULL)
	{
		char * readWhole=(char *)malloc(sizeof(char)*MAX*7);

		while(fscanf(fp,"%[^\n]\n",readWhole)!=EOF)
		{
			char *spl[7];
			for(int i=0;i<7;i++)
			{
				spl[i]=(char *)malloc(sizeof(char)*MAX);
			}
			char * copy=(char *)malloc(sizeof(char)*7*MAX);
			strcpy(copy,readWhole);
			
			//printf("%d\t",strlen(copy));
			
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
			
			//printf("%d\n",tmp);
			
			if(counter==size)
			{
				size*=2;
				triples=(char **)realloc(triples,sizeof(char *)*size);
			}
			
			triples[j]=(char *)malloc(sizeof(char)*tmp);
			strcpy(triples[j],"");

			for(int i=0;i<7;i++)
			{
				strcat(triples[j],spl[i]);
				if(i!=6)
					strcat(triples[j],"|");
			}	
			strcat(triples[j],"\0");

			//printf("%s\n",triples[j]);
			counter++;
			j++;

			for(int i=0;i<7;i++)
			{
				free(spl[i]);
			}
		}
	}

	if(counter==size)
	{
		size+=1;
		triples=(char **)realloc(triples,sizeof(char *)*size);
	}
	triples[j]=NULL;
	return triples;
}
