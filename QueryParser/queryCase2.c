#include "Parser.h"
#define MAX 512
typedef enum tri {SUB=0, PRED=1, OBJ=2} tri;

char ** solveSimpleSelectQueryCase2(char* subject,char* predicate,char* object)
{
	//Case 2
	//<?,?,Resource> and <?,Resource,?>

	
	//Subcase 1

	char ** triples;

	int j=0;
	if((predicate==NULL && object!=NULL) || (predicate!=NULL && object==NULL))
	{
		int len=strlen(object);
		len+=4;
		
		char * name=(char *)malloc(sizeof(char)*len);
		
		strcpy(name,object);
		strcat(name,".gdf\0");

		FILE * fp=fopen(name,"r");

		int n1,n2,n3;

		fscanf(fp,"# %d %d %d",&n1,&n2,&n3);

		triples=(char **)malloc(sizeof(char *)*n3);

		char ignore[100];

		fscanf(fp,"%[^\n]\n",ignore);		//ignore the metadata line

		fscanf(fp,"%[^\n]\n",ignore);		//ignore the @Subject line

		while(n1--)
		{
			fscanf(fp,"%[^\n]\n",ignore);		//ignore all n1 lines
		}
		
		char uri[MAX], uid[MAX];
		FILE * fp_1;
		int n;
		if(object!=NULL)
		{
			fscanf(fp,"%[^\n]\n",ignore);		//ignore the @Predicate line
			while(n2--)
				fscanf(fp,"%[^\n]\n",ignore);	//ignore all n2 lines
			fscanf(fp,"%[^\n]\n",ignore);		//ignore the @Object line
			n=n2;
		}
		else
		{
			fscanf(fp,"%[^\n]\n",ignore);		//ignore the @Predicate line
			n=n3;
		}

		while(n--)
		{
			fscanf(fp,"%s %s",uri,uid);
			fp_1=fopen(uri,"r");
			searchAndInsert(fp_1,uid,triples,j);
			j++;
			fclose(fp_1);
		}
	}
	return triples;
}

void searchAndInsert(FILE * fp, char  key[], char ** triples, int index)
{
	char ignore[100];

	int n1,n2,n3;

	fscanf(fp,"# %d %d %d",&n1,&n2,&n3);

	fscanf(fp,"%[^\n]\n",ignore);		//eat the metadata line
	fscanf(fp,"%[^\n]\n",ignore);		//eat the @Subject line

	while(n1--)
	{

		char * spl[7];

		char * readWhole=(char *)malloc(sizeof(char)*7*MAX);

		fscanf(fp,"%s\n",readWhole);

		for(int i=0;i<7;i++)
		{
			spl[i]=(char *)malloc(sizeof(char)*MAX);
		}

		for(int i=0;i<7;i++)
		{
			strcpy(spl[i],strsep(&readWhole,"|"));
		}
		if(strcmp(spl[0],key)==0)
		{
			int tmp=0;
			for(int i=0;i<7;i++)
			{
				tmp+=strlen(spl[i]);
			}
			tmp+=7;

			
			triples[index]=(char *)malloc(sizeof(char)*tmp);
			for(int i=0;i<7;i++)
			{
				strcat(triples[index],spl[i]);
				strcat(triples[index],"|\0");
			}
			return;	
		}
	}
}


