#include "queryEngine.h"

void insertTuple(char* subject,char* predicate,char* object)
{
	//FOR dist.gdf-----------------------------------------------------
	FILE * ptr = fopen("dist.gdf","a");
	char arr[MAX];
	char * tuple=(char *)malloc(sizeof(char)*3*MAX);
	strcpy(tuple,subject);
	strcat(tuple," ");
	strcat(tuple,predicate);
	strcat(tuple," ");
	strcat(tuple,object);
	fprintf(ptr,"%s|%s||%s||%s|\n",md5sum(tuple),subject,predicate,object);
	fclose(ptr);
	//--------------------------------------------------------------------



	FILE * tmp_ptr;
	char toRead[7*MAX];
	int n1,n2,n3,tmp;
	//FOR subject file --------------------------------------------------
	char name[MAX];
	strcpy(name,"./GDF/res/");
	strcat(name,subject);
	strcat(name,".gdf");
	FILE * sptr = fopen(name,"r");

	if(sptr==NULL)
	{
		sptr=fopen(name,"w");
		fprintf(sptr,"%d %d %d\n",1,0,0);
		fprintf(sptr,"%s\n","metadata");
		fprintf(sptr,"%s\n","@Subject");
		fprintf(sptr,"%s|%s||%s||%s|\n",md5sum(tuple),subject,predicate,object);
		fprintf(sptr,"%s\n","@Predicate");
		fprintf(sptr,"%s\n","@Object");
		fclose(sptr);
	}
	else
	{
		tmp_ptr=fopen("./GDF/res/tmp_create.gdf","w");

		fscanf(sptr,"%d %d %d\n",&n1,&n2,&n3);

		fprintf(tmp_ptr,"%d %d %d\n",n1+1,n2,n3);

		fscanf(sptr,"%[^\n]\n",toRead);		//for metadata line
		fprintf(tmp_ptr,"%s\n",toRead);
		fscanf(sptr,"%[^\n]\n",toRead);		//for @Subject line
		fprintf(tmp_ptr,"%s\n",toRead);
		fprintf(tmp_ptr,"%s|%s||%s||%s|\n",md5sum(tuple),subject,predicate,object);

		while(fscanf(sptr,"%[^\n]\n",toRead)!=EOF)
		{
			fprintf(tmp_ptr,"%s\n",toRead);
		}
		fclose(sptr);
		fclose(tmp_ptr);
		remove(name);
		rename("./GDF/res/tmp_create.gdf",name);
	}
	//---------------------------------------------------------------------



	//FOR object file------------------------------------------------------
	
	strcpy(name,"./GDF/res/");
	strcat(name,object);
	strcat(name,".gdf");

	FILE * optr=fopen(name,"r");	
	if(optr==NULL)
	{
		optr=fopen(name,"w");
		fprintf(optr,"%d %d %d\n",0,0,1);
		fprintf(optr,"%s\n","metadata");
		fprintf(optr,"%s\n","@Subject");
		fprintf(optr,"%s\n","@Predicate");
		fprintf(optr,"%s\n","@Object");	
		char predTuple[MAX*3];
		strcpy(predTuple,"./GDF/res/");
		strcat(predTuple,subject);
		strcat(predTuple,".gdf");
		fprintf(optr,"%s : %s\n",predTuple,md5sum(tuple));
		fclose(optr);
	}
	else
	{
		tmp_ptr=fopen("./GDF/res/tmp_create.gdf","w");
		fscanf(optr,"%d %d %d\n",&n1,&n2,&n3);

		fprintf(tmp_ptr,"%d %d %d\n",n1,n2,n3+1);

		tmp=n1+n2+4;
		while(tmp--)
		{
			fscanf(optr,"%[^\n]\n",toRead);
			fprintf(tmp_ptr,"%s\n",toRead);
		}
		char predTuple[MAX*3];
		strcpy(predTuple,"./GDF/res/");
		strcat(predTuple,subject);
		strcat(predTuple,".gdf");
		fprintf(tmp_ptr,"%s : %s\n",predTuple,md5sum(tuple));

		while(n3--)
		{
			fscanf(optr,"%[^\n]\n",toRead);
			fprintf(tmp_ptr,"%s\n",toRead);
		}
		fclose(optr);
		fclose(tmp_ptr);
		remove(name);
		rename("./GDF/res/tmp_create.gdf",name);
	}
	//-----------------------------------------------------------------------


	//FOR predicate line-----------------------------------------------------
	strcpy(name,"./GDF/pred/");
	strcat(name,predicate);
	strcat(name,".gdf");

	FILE * prptr=fopen(name,"r");

	if(prptr==NULL)
	{
		prptr=fopen(name,"w");
		fprintf(prptr,"%d %d %d\n",0,1,0);
		fprintf(prptr,"%s\n","metadata");
		fprintf(prptr,"%s\n","@Subject");
		fprintf(prptr,"%s\n","@Predicate");
		char predTuple[MAX*3];
		strcpy(predTuple,"./GDF/res/");
		strcat(predTuple,subject);
		strcat(predTuple,".gdf");
		fprintf(prptr,"%s : %s\n",predTuple,md5sum(tuple));
		fprintf(prptr,"%s\n","@Object");	
		fclose(prptr);
	}
	else
	{
		tmp_ptr=fopen("./GDF/pred/tmp_create.gdf","w");
		fscanf(prptr,"%d %d %d\n",&n1,&n2,&n3);

		fprintf(tmp_ptr,"%d %d %d\n",n1,n2+1,n3);

		tmp=n1+3;
		while(tmp--)
		{
			fscanf(prptr,"%[^\n]\n",toRead);
			fprintf(tmp_ptr,"%s\n",toRead);
		}
		char predTuple[MAX*3];
		strcpy(predTuple,"./GDF/res/");
		strcat(predTuple,subject);
		strcat(predTuple,".gdf");

		fprintf(tmp_ptr,"%s : %s\n",predTuple,md5sum(tuple));

		while(fscanf(prptr,"%[^\n]\n",toRead)!=EOF)
		{
			fprintf(tmp_ptr,"%s\n",toRead);
		}
		fclose(prptr);
		fclose(tmp_ptr);
		remove(name);
		rename("./GDF/pred/tmp_create.gdf",name);	
	}
}
