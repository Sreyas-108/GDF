#include "selectQuery.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);

	char ** triples=parseQuery(argv[1]);
	deleteTuple(triples[0],triples[1],triples[2]);
	return 0;
}
