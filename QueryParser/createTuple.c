#include<stdio.h>

void insertTuple(char* subject,char* predicate,char* object){
    File* ptr = fopen("Distribution.txt","w");
    char arr[50];
    char* tuple;
    strcat(tuple,subject);
    strcat(tuple,predicate);
    strcat(tuple,object);
    fprintf(ptr,"%s|%s||%s||%s|",md5sum(tuple),subject,predicate,object);
    
    File* sptr = fopen(strcat(subject,".txt"),"w");
    
    if(feof(sptr)){
        printf("@SUBJECT\n@PREDICATE\n@OBJECT\n");
    }

    while(1){
        if(feof(sptr)){
            printf("@SUBJECT was not found. Try again");
            return;
        }
        else{
            fscanf(sptr,"%[^\n]\0",arr);
            fgetc(sptr);
            if(strcmp(arr,"@SUBJECT") == 0){
                fprintf(sptr,"%s|%s||%s||%s|\n",md5sum(tuple),subject,prediacte,object);
                break;
            }
        }
    }
    
    File* prptr = fopen(strcat(predicate,".txt"),"w");
    
    if(feof(prptr)){
        printf("@SUBJECT\n@PREDICATE\n@OBJECT\n");
    }
    
    while(1){
        if(feof(prptr)){
            printf("@PREDICATE was not found. Try again");
            return;
        }
        else{
            fscanf(prptr,"%[^\n]\0",arr);
            fgetc(prptr);
            if(strcmp(arr,"@PREDICATE") == 0){
                fprintf(prptr,"%s:%s\n",suject,md5sum(tuple));
                break;
            }
        }
    }
    
    File* optr = fopen(strcat(object,".txt"),"w");
    
    if(feof(optr)){
        printf("@SUBJECT\n@PREDICATE\n@OBJECT\n");
    }
    
    while(1){
        if(feof(optr)){
            printf("@OBJECT was not found. Try again");
            return;
        }
        else{
            fscanf(optr,"%[^\n]\0",arr);
            fgetc(optr);
            if(strcmp(arr,"@OBJECT") == 0){
                fprintf(optr,"%s:%s\n",suject,md5sum(tuple));
                break;
            }
        }
    }
}
