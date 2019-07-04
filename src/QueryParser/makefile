all: search delete create
search: queryCase1.o queryCase2.o queryCase3.o queryCheck searchDriver.o parser.o notLegit.o queryEngine.h
	gcc -g -o search queryCheck queryCase1.o queryCase2.o queryCase3.o searchDriver.o parser.o notLegit.o
delete: deleteCheck removeLine.o md5sum.o updateCount.o parser.o deleteDriver.o notLegit.o queryEngine.h
	gcc -g -o delete deleteCheck removeLine.o md5sum.o parser.o updateCount.o deleteDriver.o notLegit.o
create: createCheck md5sum.o parser.o createDriver.o notLegit.o queryEngine.h
	gcc -g -o create createCheck md5sum.o parser.o createDriver.o notLegit.o
queryCase1.o: queryCase1.c queryEngine.h
	gcc -g -c queryCase1.c
queryCase2.o: queryCase2.c queryEngine.h
	gcc -g -c queryCase2.c
queryCase3.o: queryCase3.c queryEngine.h
	gcc -g -c queryCase3.c
queryCheck: query.c queryEngine.h
	gcc -g -c -o queryCheck query.c
searchDriver.o: searchDriver.c queryEngine.h
	gcc -g -c searchDriver.c
parser.o: parser.c queryEngine.h
	gcc -g -c parser.c
deleteCheck: deleteTuple.c queryEngine.h
	gcc -g -c -o deleteCheck deleteTuple.c
removeLine.o: removeLine.c queryEngine.h
	gcc -g -c removeLine.c
md5sum.o: md5sum.c queryEngine.h
	gcc -g -c md5sum.c
createCheck: createTuple.c queryEngine.h
	gcc -g -c -o createCheck createTuple.c
updateCount.o: updateCount.c queryEngine.h
	gcc -g -c updateCount.c
deleteDriver.o: deleteDriver.c queryEngine.h
	gcc -g -c deleteDriver.c 
createDriver.o: createDriver.c queryEngine.h
	gcc -g -c createDriver.c
notLegit.o: notLegit.c queryEngine.h
	gcc -g -c notLegit.c
clear:
	rm *.o search delete create
