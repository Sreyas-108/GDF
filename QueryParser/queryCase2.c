#include "queryEngine.h"

char ** solveSimpleSelectQueryCase2(char* subject,char* predicate,char* object)
{
	//Case 2
	//<?,?,Resource> and <?,Resource,?> and <?,Resource,Resource>
	//Subcase 1
	char ** triples;

	int j=0;
	FILE *fp;
	int n1,n2,n3;
	if((predicate==NULL && object!=NULL) || (predicate!=NULL && object==NULL))
	{
		
		if(object!=NULL)
		{
			int len=strlen(object);
			len+=20;
			char * name=(char *)malloc(sizeof(char)*len);
			strcpy(name,"./GDF/res/\0");
			strcat(name,object);
			strcat(name,".gdf\0");
			fp=fopen(name,"r");
		}
		if(predicate!=NULL)
		{
			int len=strlen(predicate);
			len+=20;
			char * name=(char *)malloc(sizeof(char)*len);
			strcpy(name,"./GDF/pred/\0");
			strcat(name,predicate);
			strcat(name,".gdf\0");
			fp=fopen(name,"r");
		}

		if(fp==NULL)
		{
			printf("ERROR!! Resource file could not be found");
			exit(0);
		}
		fscanf(fp,"%d %d %d\n",&n1,&n2,&n3);
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
			n=n3;
		}
		else
		{
			fscanf(fp,"%[^\n]\n",ignore);		//ignore the @Predicate line
			n=n2;
		}

		triples=(char **)malloc(sizeof(char *)*(n+1));
		//printf("%d\n",n);
		while(n--)
		{
			fscanf(fp,"%s : %[^\n]\n",uri,uid);
			fp_1=fopen(uri,"r");

			if(fp_1==NULL)
			{
				printf("ERROR!! Required resource files are missing, try running init command again");
				exit(0);
			}
			searchAndInsert(fp_1,uid,triples,j,0,"");
			j++;
			fclose(fp_1);
		}
		triples[j]=NULL;
	}
	if(predicate!=NULL && object!=NULL)
	{
		int len=strlen(predicate);
		len+=20;

		char * name=(char *)malloc(sizeof(char)*len);

		strcpy(name,"./GDF/pred/");
		strcat(name,predicate);
		strcat(name,".gdf\0");

		fp=fopen(name,"r");

		char ignore[100];

		fscanf(fp,"%d %d %d\n", &n1, &n2 ,&n3);

		fscanf(fp,"%[^\n]\n",ignore);	//eat up the metadata line
		fscanf(fp,"%[^\n]\n",ignore);	//eat up the @Subject line

		while(n1--)
			fscanf(fp,"%[^\n]\n",ignore);

		fscanf(fp,"%[^\n]\n",ignore);	//eat up the predicate line

		char uri[MAX], uid[MAX];
		
		triples=(char **)malloc(sizeof(char *)*(n2+1));
		
		for(int i=0;i<(n2+1);i++)
		{
			triples[i]=NULL;
		}
		FILE * fp_1;
		j=0;
		while(n2--)
		{
			fscanf(fp,"%s : %[^\n]\n",uri,uid);
			fp_1=fopen(uri,"r");
			searchAndInsert(fp_1, uid, triples,j,1,object);

			if(fp_1==NULL)
			{
				printf("ERROR!! Required resource files are missing, try running init command again");
				exit(0);
			}
			fclose(fp_1);
			if(triples[j]!=NULL)
				j++;
		}
		triples[j]=NULL;
	}
	return triples;
}

void searchAndInsert(FILE * fp, char  key[], char ** triples, int index, int flag, char flagCmp[])
{
	char ignore[100];

	int n1,n2,n3;

	fscanf(fp,"%d %d %d\n",&n1,&n2,&n3);

	fscanf(fp,"%[^\n]\n",ignore);		//eat the metadata line
	fscanf(fp,"%[^\n]\n",ignore);		//eat the @Subject line

	char *spl[7];
	while(n1--)
	{
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
			if(flag==0 || (flag==1 && strcmp((spl[5]),flagCmp)==0))
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
					if(i!=6)
						strcat(triples[index],"|");
				}	
				strcat(triples[index],"\0");
			}
			return;	
		}
	}
}
