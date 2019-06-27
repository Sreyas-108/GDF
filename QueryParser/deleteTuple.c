#include "removeLine.h"

void deleteTuple(char* subject,char* predicate,char* object){
	FILE* ptr = fopen("/dist.gdf","w");
	FILE* pptr = fopen("/dist.gdf","w");
	char* tuple;
	int flag = 0;
	while(1)
	{
		if(feof(ptr))
		{
			printf("The given tuple was not found in the file. Please try something else.\n");
			return;
		}
		else
		{
			char * arr=(char *)malloc(sizeof(char)*MAX*7);
			fscanf(ptr,"%[^\n]\n",arr);
			char * spl[7];
			for(int i=0;i<7;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}
			
			for(int i=0;i<7;i++)
			{
				strcpy(spl[i],strsep(&arr,"|"));
			}
			if(strcmp(spl[1],subject)==strcmp(spl[3],predicate)==strcmp(spl[5],object)==0)
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
		pptr = ptr;
	}
	removeLine("/dist.gdf",pptr);
	fclose(ptr);	
	fclose(pptr);

	char* sub_copy = malloc(sizeof(char)*(strlen(subject) + 1));        //strcat, used later, changes contents of subject char ptr
	strcpy(sub_copy,subject);                                           //so creating a copy of the contents of subject
	char* pre_copy = malloc(sizeof(char)*(strlen(predicate) + 1));
	strcpy(pre_copy,predicate);
	char* obj_copy = malloc(sizeof(char)*(strlen(object) + 1));
	strcpy(obj_copy,object);

	strcpy(subject,"/GDF/res/");
	strcat(subject,sub_copy);
	strcat(subject,".gdf");
	
	strcpy(predicate,"/GDF/pred/");
	strcat(predicate,pre_copy);
	strcat(predicate,".gdf");
	
	strcpy(object,"/GDF/res/");
	strcat(object,obj_copy);
	strcat(object,".gdf");
	FILE* sptr = fopen(subject,"w");
	FILE* prptr = fopen(predicate,"w");
	FILE* optr = fopen(object,"w");

	fclose(pptr);
	pptr = fopen(subject,"w");
	while(1){
		if(feof(sptr)){
			printf("The given tuple was not found in the subject file. Please try something else.");
			return;
		}
		else{
			fchar * arr=(char *)malloc(sizeof(char)*MAX*7);
			fscanf(sptr,"%[^\n]\n",arr);
			char * spl[7];
			for(int i=0;i<7;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}
			
			for(int i=0;i<7;i++)
			{
				strcpy(spl[i],strsep(&arr,"|"));
			}
			if(strcmp(spl[1],subject)==strcmp(spl[3],predicate)==strcmp(spl[5],object)==0){
				removeLine(subject,pptr);
				break;
			}
		}
		pptr = sptr;
	}
	fclose(pptr);
	pptr = fopen(predicate,"w");
	while(1){
		if(feof(prptr))
		{
			printf("The given tuple was not found in the predicate file. Please try something else.\n");
			return;
		}
		else
		{
			char * arr=(char *)malloc(sizeof(char)*MAX*2);
			fscanf(prptr,"%[^\n]\n",arr);
			char * spl[2];
			for(int i=0;i<2;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}
			
			for(int i=0;i<2;i++)
			{
				strcpy(spl[i],strsep(&arr," : "));
			}

			if(strcmp(arr,"@PREDICATE")==0){
				flag = 1;
			}
			if(strcmp(arr,"@OBJECT")==0){
				flag = 0;
			}
			if(strcmp(spl[0],subject)==strcmp(spl[1],md5sum(tuple)==0 && flag == 1)){
				removeLine(predicate,pptr);
				break;
			}                                   
		}
		pptr = prptr;
	}
	fclose(pptr);
	flag = 0;

	FILE* pptr = fopen(object,"w");
	while(1){
		if(feof(optr)){
			printf("The given tuple was not foound in the object file. Please try something else.");
			return;
		}
		else{
			char * arr=(char *)malloc(sizeof(char)*MAX*2);
			fscanf(optr,"%[^\n]\n",arr);
			char * spl[2];
			for(int i=0;i<2;i++)
			{
				spl[i]=(char *) malloc(sizeof(char)*MAX);
			}
			
			for(int i=0;i<2;i++)
			{
				strcpy(spl[i],strsep(&arr," : "));
			}
			if(strcmp(arr,"@OBJECT")==0){
				flag = 1;
			}
			if(strcmp(spl[0],subject)==strcmp(spl[1],md5sum(tuple)==0 && flag == 1)){
				removeLine(object,pptr);
		}
		pptr = optr;
	}
}
