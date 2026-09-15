#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "feerror.h"
#include "fefiles.h"


//only for joining strs
char* concat(const char* str1, const char* str2) {
    char* isconcat = malloc(strlen(str1) + strlen(str2) + 1);
    if (isconcat == NULL) isconcat = NULL;
    strcpy(isconcat,str1);
    strcat(isconcat,str2);
    return isconcat;
}

//Expanded to OPEN_FILE macro
//Opens A File By Giving Its FilePath And File Argument
int open_file(const char* file_path, FILE** file) {
    if (!file_path) {
        return NULL_PATH_ERROR;
    }
    *file = fopen(file_path,"r");
    if (!*file) {
        return FILE_PATH_ERROR;
    }
    return FILE_OPEN_SUCCESS;
}

//Expanded to FILE_TEXT macro
//Fetch All Text From A File That Supports UTF-8 .fe and .fb
int get_file_text(FILE* file,const char** content) {
    if (!file) {
        return NULL_FILE_ERROR;
    }

    char* total_content = malloc(1);
    total_content[0] = '\0';

    char buffer[256];

    while (fgets(buffer,sizeof(buffer),file) != NULL) {
        char* concatres = concat(total_content,buffer);
        
        free(total_content);
        total_content = concatres;
        //printf("\n cont: %s",total_content);
    }
    //total_content[sizeof(total_content) + 1] = '\0';
    *content = total_content;
    //total_content = NULL;
    return FILE_CONTENT_FETCH_SUCCESS;
}

//Expanded to CREATE_FILE macro
//Creates A File That Supports UTF-8 .fe and .fb
int create_file(const char* file_path, FILE** file_result) {
    *file_result = fopen(file_path,"w");
    if (!*file_result) {
        return CREATE_FILE_ERROR;
    }
    return FILE_CREATION_SUCCESS;
}

//Expanded to WRITE_TEXT_FILE macro
//Writes A File Giving Contents To Write
int write_file_text( const char* content, FILE** file_result) {
    if (!*file_result) {
        return NULL_FILE_ERROR;
    }
    fputs(content,*file_result);

    return FILE_WRITE_SUCCESS;
}