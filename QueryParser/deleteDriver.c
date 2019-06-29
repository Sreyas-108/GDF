#include "queryEngine.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);

	char ** triples;
	triples=parseQuery(argv[1]);

	deleteTuple(triples[0],triples[1],triples[2]);

	return 0;
}
