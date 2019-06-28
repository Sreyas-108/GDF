#include "selectQuery.h"

int main(int argc, char ** argv)
{
	if(argc!=2)
		exit(0);

	char ** triples;

	char * inp=argv[1];

	triples=parseQuery(inp);

	/*for(int i=0;i<3;i++)
	{
		if(triples[i]!=NULL)
			printf("%s\n",triples[i]);
		else
			printf("NULL\n");
	}*/
	char ** xyz=query(triples[0],triples[1],triples[2]);

	int j=0;
	while(xyz[j]!=NULL)
	{
		printf("%s\n",xyz[j]);
		j++;
	}
	return 0;
}
