// For '?', pass a NULL pointer

// Query is of the format <any,any,any> 
// Returns an array containing three pointers in the order subject,predicate,object
char **parseQuery(char *query); 

// Returns an array of triplets of size n*3
char **solveSimpleSelectQuery(char* subject,char* predicate,char* object);

