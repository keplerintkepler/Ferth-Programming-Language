#ifndef FERTH_COMPILER
#define FERTH_COMPILER
#endif

#define FERTH_COMPILER_VERSION 0.1

// or -> ||
// and -> &&

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "feerror.h"
#include "fefiles.h"

//utils

int main(int argc, char** args) {
    const char* show_console = args[1];
    const char* filepath = args[2];
    const char* endpath = args[3];

    int console = 0;
    

    if (show_console == "-c" || show_console == "-console") {
        console = 1;
    }

    

    if (console) { printf("file_to_ex: %s  end_file: %s",filepath,endpath); }


    //Open File Process

    int status;
    
    fe_file current_file;

    status = OPEN_FILE(filepath,&current_file);

    if (console) { printf("\nget status: %i",status); }


    //Fetch File Process

    const char* content;

    status = FILE_TEXT(current_file,&content);

    if (console) { printf("\nfetch status: %i with content:\n\n%s",status , content); }
    //printf(content);



    /*
    Compilation Process by feparser.h
    */

    //Create File Process

    fe_file result_file;

    status = CREATE_FILE(endpath,&result_file);

    if (console) { printf("\ncreation status: %i",status); }


    //Write Process

    status = WRITE_TEXT_FILE(content,&result_file);

    if (console) { printf("\nwrite status: %i",status); }

    return 0;
}