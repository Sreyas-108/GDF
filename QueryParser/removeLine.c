#include "removeLine.h"

void removeLine(char* filename, FILE* ptr){
	char target[512];
	fscanf(ptr,"%[^\n]\n",target);
	char arr[512];
	FILE* ptr1 = fopen(filename,"r");
	FILE* ptr2 = fopen("new_temp_file.txt","w");
	while(fscanf(ptr1,"%[^\n]\n",arr)!=EOF)
	{
		if(!strcmp(target,arr))
			continue;
		else
			fprintf(ptr2,"%s\n",arr);
	}
	fclose(ptr1);
	fclose(ptr2);
	remove(filename);
	rename("new_temp_file.txt",filename);
	return;
}
