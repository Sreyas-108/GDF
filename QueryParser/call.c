#include "Parser.h"

int main(int argc, char ** argv)
{
		if(argc!=2)
				exit(0);

		char ** triples;

		char * query=argv[1];
		
		triples=parseQuery(query);

		for(int i=0;i<3;i++)
		{
				if(triples[i]!=NULL)
					printf("%s\n",triples[i]);
				else
					printf("NULL\n");
		}
		return 0;
}
