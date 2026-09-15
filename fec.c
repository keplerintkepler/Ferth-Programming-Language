#ifndef FERTH_COMPILER
#define FERTH_COMPILER
#endif

#define FERTH_COMPILER_VERSION 0.1

// or ||
// and &&

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "feerror.h"
#include "fefiles.h"

//utils

int main(int argc, char** args) {
    const char* filepath = args[1];
    const char* endpath = args[2];
    printf("file_to_ex: %s  end_file: %s",filepath,endpath);

    int status;
    
    FILE* current_file;

    status = OPEN_FILE(filepath,&current_file);

    printf("\nget status: %i",status);

    const char* content;

    status = FILE_TEXT(current_file,&content);

    printf("\nfetch status: %i with content:\n\n%s",status , content);
    //printf(content);


    FILE* result_file;

    status = CREATE_FILE(endpath,&result_file);

    printf("\ncreation status: %i",status);

    status = WRITE_TEXT_FILE(content,&result_file);

    printf("\nwrite status: %i",status);

    //Sleep(5000);

    current_file = NULL;
    result_file = NULL;

    return 0;
}