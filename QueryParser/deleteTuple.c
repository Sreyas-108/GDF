#include "selectQuery.h"

void deleteTuple(char* subject,char* predicate,char* object){
	FILE* ptr = fopen("./dist.gdf","r");
	char* tuple;
	int flag = 0;
	char * arr=(char *)malloc(sizeof(char)*MAX*7);
	while(1)
	{
		if(feof(ptr))
		{
			printf("The given tuple was not found in the file. Please try something else.\n");
			return;
		}
		else
		{
			char * copy=(char *)malloc(sizeof(char)*MAX*7);
			fscanf(ptr,"%[^\n]\n",arr);

			strcpy(copy,arr);
			char * spl[7];
			for(int i=0;i<7;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			} 
			for(int i=0;i<7;i++)
			{
				strcpy(spl[i],strsep(&copy,"|"));
			}
			if(strcmp(spl[1],subject)==0 && strcmp(spl[3],predicate)==0 && strcmp(spl[5],object)==0)
			{
				tuple = (char*)malloc(sizeof(char)*(strlen(subject) + strlen(predicate) + strlen(object) + 3));
				strcpy(tuple,subject);
				strcat(tuple," ");
				strcat(tuple,predicate);
				strcat(tuple," ");
				strcat(tuple,object);
				break;
			}
		}
	}
	fclose(ptr);	
	removeLine("./dist.gdf",arr,0);

	char* sub_copy = malloc(sizeof(char)*(strlen(subject) + 1));        //strcat, used later, changes contents of subject char ptr
	strcpy(sub_copy,subject);                                           //so creating a copy of the contents of subject
	char* pre_copy = malloc(sizeof(char)*(strlen(predicate) + 1));
	strcpy(pre_copy,predicate);
	char* obj_copy = malloc(sizeof(char)*(strlen(object) + 1));
	strcpy(obj_copy,object);

	strcpy(subject,"./GDF/res/");
	strcat(subject,sub_copy);
	strcat(subject,".gdf");

	strcpy(predicate,"./GDF/pred/");
	strcat(predicate,pre_copy);
	strcat(predicate,".gdf");

	strcpy(object,"./GDF/res/");
	strcat(object,obj_copy);
	strcat(object,".gdf");
	FILE* sptr = fopen(subject,"r");

	while(1)
	{
		if(feof(sptr))
		{
			printf("The given tuple was not found in the subject file. Please try something else.\n");
			return;
		}
		else
		{
			char * copy=(char *)malloc(sizeof(char)*MAX*7);
			fscanf(sptr,"%[^\n]\n",arr);
			strcpy(copy,arr);
			char * spl[7];
			for(int i=0;i<7;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}

			for(int i=0;i<7;i++)
			{
				if(copy!=NULL)
					strcpy(spl[i],strsep(&copy,"|"));
			}
			if(strcmp(spl[1],sub_copy)==0 && strcmp(spl[3],pre_copy)==0 && strcmp(spl[5],obj_copy)==0)
			{
				fclose(sptr);
				removeLine(subject,arr,1);
				break;
			}
		}
	}

	FILE* prptr = fopen(predicate,"r");
	while(1)
	{
		if(feof(prptr))
		{
			printf("The given tuple was not found in the predicate file. Please try something else.\n");
			return;
		}
		else
		{
			char * copy=(char *)malloc(sizeof(char)*MAX*2);
			fscanf(prptr,"%[^\n]\n",arr);
			strcpy(copy,arr);
			if(strcmp(arr,"@Predicate")==0)
			{
				flag = 1;
			}
			if(flag!=1)
				continue;
			char * spl[3];
			for(int i=0;i<3;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}

			for(int i=0;i<3;i++)
			{
				if(copy!=NULL)
					strcpy(spl[i],strsep(&copy," "));
			}
			if(strcmp(arr,"@Object")==0)
			{
				flag = 0;
			}
			if(strcmp(spl[0],subject)==0 && strcmp(spl[2],md5sum(tuple))==0 && flag == 1)
			{
				fclose(prptr);
				removeLine(predicate,arr,2);
				break;
			}                                   
		}
	}
	flag = 0;

	FILE* optr = fopen(object,"r");
	while(1)
	{
		if(feof(optr))
		{
			printf("The given tuple was not found in the object file. Please try something else.\n");
			return;
		}
		else
		{
			char * copy=(char *)malloc(sizeof(char)*MAX*2);
			fscanf(optr,"%[^\n]\n",arr);
			strcpy(copy,arr);
			if(strcmp(arr,"@Object")==0)
			{
				flag = 1;
			}
			if(flag!=1)
				continue;
			char * spl[3];
			for(int i=0;i<3;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}

			for(int i=0;i<3;i++)
			{
				if(copy!=NULL)
					strcpy(spl[i],strsep(&copy," "));
			}
			if(strcmp(spl[0],subject)==0 && strcmp(spl[2],md5sum(tuple))==0 && flag == 1)
			{
				fclose(optr);
				removeLine(object,arr,1);
				break;
			}
		}
	}
	updateCounter(subject,0,1);
	updateCounter(object,2,1);
	updateCounter(predicate,1,1);
}
