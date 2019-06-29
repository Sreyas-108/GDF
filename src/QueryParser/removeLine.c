#include "queryEngine.h"

void removeLine(char* filename, char * target, int flag)
{
	char arr[512];
	FILE* ptr1 = fopen(filename,"r");
	FILE* ptr2;
	
	char * name=(char *)malloc(sizeof(char)*MAX);
	
	if(flag==0)
		strcpy(name,"./new_temp_file.txt");
	if(flag==1)
		strcpy(name,"./GDF/res/new_temp_file.txt");
	if(flag==2)	
		strcpy(name,"./GDF/pred/new_temp_file.txt");

	ptr2=fopen(name,"w");
	if(ptr2==NULL)
		perror("fopen");
	
	while(fscanf(ptr1,"%[^\n]\n",arr)!=EOF)
	{
		if(!strcmp(target,arr))
		{
			continue;
		}
		else
		{
			fprintf(ptr2,"%s\n",arr);
		}
	}
	fclose(ptr1);
	fclose(ptr2);
	remove(filename);
	rename(name,filename);
	return;
}

