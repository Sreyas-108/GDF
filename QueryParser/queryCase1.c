#include "selectQuery.h"

char ** solveSimpleSelectQueryCase1(char* subject,char* predicate,char* object)
{

	//Case 1
	//If Subject is a resource and predicate and ect can be anything resource or a query

	char ** triples;

	int j=0;

	if(subject!=NULL)
	{
		char * name;
		int len=strlen(subject);
		name=(char *)malloc(sizeof(char)*(len+4));	//reallocate memory for subject to be able to append .gdf

		strcat(name,subject);
		strcat(name,".gdf\0");

		FILE *fp=fopen("The_Two_Towers.gdf","r");				//Open the file in read mode

		if(fp==NULL)							//If file opening fails, return
			return;

		int n1,n2,n3;

		fscanf(fp,"# %d %d %d\n",&n1,&n2,&n3);		//Get the first line


		triples=(char **)malloc(sizeof(char *)*n1);		

		char ignore[MAX];
		fscanf(fp,"%[^\n]\n",ignore);	//eat up the metadata URI line

		fscanf(fp,"%[^\n]\n",ignore);	//eat up the @Subject line
		
		//The 3 subcases : (NULL,NULL) (Not NULL, NULL) (NULL, Not NULL)
		if((predicate!=NULL && object==NULL) || (predicate==NULL && object!=NULL) || (predicate==NULL && object==NULL))
		{
			char * spl[7];
			j=0;

			for(int i=0;i<7;i++)
			{
				spl[i]=(char *)malloc(sizeof(char)*MAX);
			}
			//Read all the tuples present in the subject.gdf file
			while(n1--)
			{
				char * readWhole=(char *)malloc(sizeof(char)*7*MAX);
				fscanf(fp,"%[^\n]\n",readWhole);

				for(int i=0;i<7;i++)
				{
					strcpy(spl[i],strsep(&readWhole,"|"));
				}

				if((object!=NULL && strcmp(spl[6],object)==0) || (predicate!=NULL && strcmp(spl[4],predicate)==0) || (predicate==NULL && object==NULL)) 
				{

					int tmp=0;
					for(int i=0;i<7;i++)
					{
						tmp+=strlen(spl[i]);
					}
					tmp+=7;

					triples[j]=(char *)malloc(sizeof(char)*tmp);

					for(int i=0;i<7;i++)
					{
						strcat(triples[j],spl[i]);
						if(i!=6)
							strcat(triples[j],"|\0");
					}
					j++;
				}
			}
			triples[j]=NULL;
		}

		//The final subcase (Not NULL, Not NULL)
		if(predicate!=NULL && object!=NULL)
		{
			bool found=false;
			char * spl[7];
			for(int i=0;i<7;i++)
			{
				spl[i]=(char *)malloc(sizeof(char)*MAX);
			}
			while(n1--)			//Read all the tuples
			{

				//If found: triples will contain the input
				//else : it will return NULL pointer

				char * readWhole=(char *)malloc(sizeof(char)*7*MAX);
				fscanf(fp,"%[^\n]\n",readWhole);

				for(int i=0;i<7;i++)
				{
					strcpy(spl[i],strsep(&readWhole,"|"));
				}
	
				if(strcmp(subject,spl[1])==0 && strcmp(spl[5],object)==0 && strcmp(spl[3],predicate)==0)
				{
					found=true;
					
					int tmp=0;
					for(int i=0;i<7;i++)
					{
						tmp+=strlen(spl[i]);
					}
					tmp+=7;

					triples[0]=(char *)malloc(sizeof(char)*tmp);

					for(int i=0;i<7;i++)
					{
						strcat(triples[0],spl[i]);
						if(i!=6)
							strcat(triples[0],"|\0");
					}
					break;
				}
			}
			if(found==false)
				triples[0]=NULL;
			else
				triples[1]=NULL;
		}
	}
	else
		return;
	return triples;
}




