#include "query.h"

int notLegit(char* arr){
	char * iter = malloc(sizeof(char));
	iter = arr;
	while(*iter != '\0'){
		if(!( *iter <='z' && *iter >= 'a' || *iter<='Z' && *iter >= 'A' || *iter <= '9' && *iter >= '0' || *iter == ' '))
			return 1;
		iter++;
	}
	return 0;
}



