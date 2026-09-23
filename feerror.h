#ifndef FERTH_ERROR_H
#define FERTH_ERROR_H


//  error values
// memory
#define MEMORY_ALLOC_ERROR 0x0F0

// path
#define NULL_PATH_ERROR 0x1F0
#define FILE_PATH_ERROR 0x1F1
// files
#define NULL_FILE_ERROR 0x2F1
#define OPEN_FILE_ERROR 0x2F2
#define CREATE_FILE_ERROR 0x2F3
// arguments
#define NULL_ARGUMENT_ERROR 0x6F0
#define INVALID_ARGUMENT_ERROR 0x6F1
#define CAST_CONVERSION_ERROR 0x6F2
#define CONVERSION_ERROR 0x6F3
// other
#define FETCH_ERROR 0x7F1

//  success values
// files
#define FILE_OPEN_SUCCESS 0x100
#define FILE_CREATION_SUCCESS 0x101
#define FILE_WRITE_SUCCESS 0x102
#define FILE_CONTENT_FETCH_SUCCESS 0x103
#define FILE_CLOSE_SUCCESS 0x104
// conversion
#define CAST_CONVERSION_SUCCESS 0x200
#define CONVERSION_SUCCESS 0x201

//functions

#define ERROR_NAME(er_code) fe_error_name(er_code)
#define FILE_ERROR_LOG(er_code,info,fn_error_log) fe_file_error_log(er_code,info,fn_error_log)
#define ERROR_INFO fe_error_info

#include "fefiles.h"

struct fe_file;

typedef struct {
    fe_file error_file;
    char* error_row;
    char* error_column;
    char* error_scope;
    char* error_code_line;
    char* error_name;
    char* error_desc;
    char* error_suggestion;
} fe_error_info;

char* fe_error_name(int error_code);

void fe_file_error_log(int error_code,fe_error_info info,char** final_error_log);

#endif