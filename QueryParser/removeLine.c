#include<stdio.h>

void removeLine(char* filename, File* ptr){
    char trash;
    char arr[50];
    File* ptr1 = fopen(filename,"r");
    File* ptr2 = fopen("new_temp_file.txt","w");
    while(1){
        if(feof(ptr1)){
            fclose(ptr1);
            fclose(ptr2);
            break;
        }
        if(ptr1 == ptr){
            continue;
        }
        else{
            fscanf(ptr1,"%[^\n]\0",arr);
            fprintf(ptr2,"%s",arr);
            fgetc(ptr1);
        }
    }
    remove(filename);
    rename("new_temp_file.txt",filename);
    return;
}
