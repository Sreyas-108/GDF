#include<stdio.h>
#include "removeLine.h"

void deleteTuple(char* subject,char* predicate,char* object){
    File* ptr = fopen("Distribution.txt","w");
    File* pptr = fopen("Distribution.txt","w");
    char* tuple;
    char arr[50];
    char** tempT;
    int flag = 0;
    while(1){
        if(feof(ptr)){
            printf("The given tuple was not foound in the file. Please try something else.");
            return;
        }
        else{
            fscanf(ptr,"%[^\n]\0",arr);
            fgetc(ptr);
            tempT = parseTuple(arr);
            if(strcmp(tempT[0],subject)==strcmp(tempT[1],predicate)==strcmp(tempT[2],object)==0){
                tuple = malloc(sizeof(char)*(strlen(arr) + 1));
                strcpy(tuple,arr);
                break;
            }
        }
        pptr = ptr;
    }
    removeLine("Distribution.txt",pptr);
    char* sub_copy = malloc(sizeof(char)*(strlen(subject) + 1));        //strcat, used later, changes contents of subject char ptr
    strcpy(sub_copy,subject);                                           //so creating a copy of the contents of subject
    char* pre_copy = malloc(sizeof(char)*(strlen(predicate) + 1));
    strcpy(pre_copy,subject);
    char* obj_copy = malloc(sizeof(char)*(strlen(object) + 1));
    strcpy(obj_copy,subject);
    File* sptr = fopen(strcat(subject,".txt"),"w");
    File* prptr = fopen(strcat(predicate,".txt"),"w");
    File* optr = fopen(strcat(object,".txt"),"w");
    
    while(1){
        File* pptr = fopen(subject,"w");
        if(feof(sptr)){
            printf("The given tuple was not foound in the subject file. Please try something else.");
            return;
        }
        else{
            fscanf(sptr,"%[^\n]\0",arr);
            fgetc(sptr);
            tempT = parseTuple(arr);
            if(strcmp(tempT[0],subject)==strcmp(tempT[1],predicate)==strcmp(tempT[2],object)==0){
                removeLine(subject,pptr);
                break;
            }
        }
        pptr = sptr;
    }
    
    while(1){
        File* pptr = fopen(predicate,"w");
        if(feof(prptr)){
            printf("The given tuple was not foound in the predicate file. Please try something else.");
            return;
        }
        else{
            fscanf(prptr,"%[^\n]\0",arr);
            fgetc(prptr);
            if(strcmp(arr,"@PREDICATE")==0){
                flag = 1;
            }
            if(strcmp(arr,"@OBJECT")==0){
                flag = 0;
            }
            tempT = parseTuple(arr);
            if(strcmp(tempT[0],subject)==strcmp(tempT[1],md5sum(tuple)==0 && flag == 1)){
                removeLine(predicate,pptr);
                break;
            }                                     //Need to implement function which calculates md5 sum
        }
        pptr = prptr;
    }
    
    flag = 0;
    
     while(1){
        File* optr = fopen(object,"w");
        if(feof(optr)){
            printf("The given tuple was not foound in the object file. Please try something else.");
            return;
        }
        else{
            fscanf(optr,"%[^\n]\0",arr);
            fgetc(optr);
            if(strcmp(arr,"@OBJECT")==0){
                flag = 1;
            }
            tempT = parseTuple(arr);
            if(strcmp(tempT[0],subject)==strcmp(tempT[1],md5sum(tuple)==0 && flag == 1)){
                removeLine(predicate,pptr);
                break;
            }                                     //Need to implement function which calculates md5 sum
        }
        pptr = optr;
    }
}
