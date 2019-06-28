#include "selectQuery.h"

void updateCounter(char * fileName, int flag, int toDo)
{
	FILE * fp=fopen(fileName,"r");

	char path[MAX];
	if(flag==0 || flag==1)
		strcpy(path,"./GDF/res/");
	else
		strcpy(path,"./GDF/pred/");
	strcat(path,"tmp.gdf");
	FILE * tmp=fopen(path,"w");
	int n1,n2,n3;

	fscanf(fp,"%d %d %d\n",&n1,&n2,&n3);
	
	if(toDo==0)
	{
		if(flag==0)
			n1+=1;
		if(flag==1)
			n2+=1;
		if(flag==2)
			n3+=1;
	}
	else
	{	
		if(flag==0)
			n1-=1;
		if(flag==1)
			n2-=1;
		if(flag==2)
			n3-=1;
	}

	fprintf(tmp,"%d %d %d\n",n1,n2,n3);

	char arr[MAX*7];
	while(fscanf(fp,"%[^\n]\n",arr)!=EOF)
	{
		fprintf(tmp,"%s\n",arr);
	}
	remove(fileName);
	rename(path,fileName);
}
