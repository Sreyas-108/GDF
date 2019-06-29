#include "queryEngine.h"

char * md5sum(char * pqr)
{
	char * arr=(char *)malloc(sizeof(char)*35);	
	char command[70];
	snprintf(command,sizeof(command),"echo %s|md5sum",pqr);
	FILE *fp=popen(command,"r");
	fscanf(fp,"%s",arr);
	fclose(fp);

	return arr;
}
