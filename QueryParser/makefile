all: exe
exe: queryCase1.o queryCase2.o queryCase3.o query.o driver.o parser.o selectQuery.h
	gcc -g -o exe query.o queryCase1.o queryCase2.o queryCase3.o driver.o parser.o
queryCase1.o: queryCase1.c selectQuery.h
	gcc -g -c queryCase1.c
queryCase2.o: queryCase2.c selectQuery.h
	gcc -g -c queryCase2.c
queryCase3.o: queryCase3.c selectQuery.h
	gcc -g -c queryCase3.c
query.o: query.c selectQuery.h
	gcc -g -c query.c
driver.o: queryCase1.c selectQuery.h
	gcc -g -c driver.c
parser.o: parser.c selectQuery.h
	gcc -g -c parser.c
clear:
	rm *.o exe
