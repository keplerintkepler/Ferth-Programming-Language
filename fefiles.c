#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "feerror.h"
#include "fefiles.h"
#include "feutils.h"
#include "fefiles.h"

#ifdef _WIN32
#include <windows.h>
#define abspath(relpath,Sz) NULL
#define set_abspath(Path,Sz,abspath) _wfullpath(Sz,Path, MAX_PATH)
#else
#include <limits.h>
#define abspath(Path,Sz) realpath(Path,Sz)
#endif

int get_abs_path(char* rel_path, char** abspath) {
    wchar_t* wrelpath;
    wchar_t* wtempabspath;
    char* tempabspath;
    CHAR_TO_WCHART(rel_path,wrelpath);

    //Linux Def (sets to null via windows macros)
    wtempabspath = abspath(rel_path,NULL);
    WCHART_TO_CHAR(wtempabspath ,tempabspath);

    //if null (WIN32) sets path by windows method
    if (tempabspath == NULL) {
        tempabspath = set_abspath(wrelpath,NULL,*abspath);
    }
    
    *abspath = tempabspath;
}

//Expanded to OPEN_FILE macro
/*
Opens A File By Giving Its File Path And File Argument
*/

int open_file(char* file_path, fe_file* file) {
    if (!file_path) {
        return NULL_PATH_ERROR;
    }
    file -> fileobj = fopen(file_path,"r");
    file -> filepath = file_path;
    get_abs_path(file_path,&(file -> absolute_path));
    if (!file->filepath)
    if (!file->fileobj) {
        return FILE_PATH_ERROR;
    }
    return FILE_OPEN_SUCCESS;
}

//Expanded to FILE_TEXT macro
/*
Fetch All Text From A File That Supports UTF-8 .fe and .fb
*/
int get_file_text(fe_file file, char** content) {
    FILE* fileobject = file.fileobj;

    if (!fileobject) {
        return NULL_FILE_ERROR;
    }

    char* total_content = malloc(1);
    total_content[0] = '\0';

    char buffer[256];

    while (fgets(buffer,sizeof(buffer),fileobject) != NULL) {
        char *concatres;
        C_CONCAT(total_content,buffer,&concatres);
        
        
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
/*
Creates A File That Supports UTF-8 .fe and .fb
*/
int create_file(char* file_path, fe_file* file_result) {
    file_result -> fileobj = fopen(file_path,"w");
    file_result -> filepath = file_path;
    if (!file_result -> fileobj) {
        return CREATE_FILE_ERROR;
    }
    return FILE_CREATION_SUCCESS;
}

//Expanded to WRITE_TEXT_FILE macro
/*
Writes A File Giving Contents To Write
*/
int write_file_text(char* content, fe_file* file_result) {
    if (!file_result->fileobj) {
        return NULL_FILE_ERROR;
    }
    fputs(content,file_result->fileobj);

    return FILE_WRITE_SUCCESS;
}

int close_file(fe_file file) {
    if (!file.fileobj) {
        return NULL_FILE_ERROR;
    }
    fclose(file.fileobj);
    return FILE_CLOSE_SUCCESS;
}