#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <float.h>
#include <string.h>
#include <math.h>
#include "feerror.h"
#include "fetypes.h"


//Type util Def
//

/*
Converts char* to Fe_String
ERRORS:
NullArgumentError -> when it doenst have a argument (!value)
RETURNS:
CONVERSION_SUCCESS -> conversion process was succeded
*/ 
int charp_to_fe_string(const char* value, fe_string* return_val) {
    if (!value) {
        return NULL_ARGUMENT_ERROR;
    }

    return_val->str_ref = value;
    return_val->len = strlen(value);

    return CONVERSION_SUCCESS;
}

/*
Converts Fe_String to char*
ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_string.str_ref or !(*(char**))) or (!char*)

RETURNS:
CONVERSION_SUCCESS -> conversion process was succeded
*/ 
int fe_string_to_charp(fe_string value, const char** return_value) {
    if (!(*return_value) | !value.str_ref)
        return NULL_ARGUMENT_ERROR;
    char* newchar = value.str_ref;
    return CONVERSION_SUCCESS;
}


/*
Converts int to char*
Decodes int's numerals for ascii conversion(957 -> 9,5,7)

ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_string.str_ref or !(*(char**))) or (!char*)

RETURNS:
CONVERSION_SUCCESS -> conversion process was succeded
*/ 
int int_to_charp(int value, const char** return_val) {
    
}

/*
Converts char to int
Basically Ascii to ascii number ref
(USES CASTING)

ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_string.str_ref or !(*(char**))) or (!char*)
CastConversionError -> casting process failed (cast_result == NULL)

RETURNS:
CONVERSION_SUCCESS -> conversion process was succeded
*/ 
int char_to_int(char value,int* return_val) {
    if (!(*return_val))
        return NULL_ARGUMENT_ERROR;
        
    int casted_result = (int)value;

    if (!casted_result)
        return CAST_CONVERSION_ERROR;
    
    return CAST_CONVERSION_SUCCESS;
}



/*
Converts int to char (using number as ascii reference)
(USES CASTING)

ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_string.str_ref or !(*(char**))) or (!char*)
CastConversionError -> casting process failed

RETURNS:
CAST_CONVERSION_SUCCESS -> casting process was succeded
*/ 
int int_to_char_ascii(int value, const char* return_val) {
    if (!value)
        return NULL_ARGUMENT_ERROR;
    
    char casted = (char)value;
    if (!casted)
        return CAST_CONVERSION_ERROR;
    
    return_val = &casted;
    return CAST_CONVERSION_SUCCESS;
}

/*
Converts fe_number to int


ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_string.str_ref or !(*(char**))) or (!char*)

RETURNS:
CONVERSION_SUCCESS -> conversion process was succeded
*/
int fe_num_to_int(fe_number value, int* return_value) {
    if (!value.int_ref)
        return NULL_ARGUMENT_ERROR;
    
    *return_value = value.int_ref;
    return CONVERSION_SUCCESS;
}


/*
Converts fe_number to float
Number Precision is Lost
(USES CASTING)

ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_number.int_ref)
CastConversionError -> casting process failed

RETURNS:
CAST_CONVERSION_SUCCESS -> casting process was succeded
*/
int fe_num_to_float(fe_number value,float* return_value) {
    double res;
    fe_num_to_double(value,&res);
    float val = (float)res;

    if (res == NULL_ARGUMENT_ERROR || res == CAST_CONVERSION_ERROR)
        return res;

    float val = (float)res;
    if (!val)
        return CAST_CONVERSION_ERROR;
    
    return CAST_CONVERSION_SUCCESS;
}


/*
Converts fe_number to float
Maintain fe_number_precision

ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_number.int_ref or !fe_number.dec_ref)
CastConversionError -> casting process failed (!dec_digit_count)

RETURNS:
CAST_CONVERSION_SUCCESS -> conversion process was succeded
*/
int fe_num_to_double(fe_number value,double* return_value) {
    if (!value.int_ref || !value.dec_ref)
        return NULL_ARGUMENT_ERROR;
    
    double final = value.int_ref;
    double decimal;

    int dec_digit_count = abs(((int)floor(log10(value.dec_ref))) + 1);
    
    if (!dec_digit_count)
        return CAST_CONVERSION_ERROR;

    decimal = value.dec_ref / (10,dec_digit_count);

    final = final + decimal;

    *return_value = final;
    return CAST_CONVERSION_SUCCESS;
}



int fe_num_to_fe_string(fe_number value,fe_string* return_value) {
    
}

/*
Auto Converts 2 Types, calls other functions inside this .c file

Example:
fe_number x;
x.int_ref = 2;


ERRORS:
NullArgumentError -> when it doenst have a argument (!fe_string.str_ref or !(*(char**))) or (!char*)

RETURNS:
CONVERSION_SUCCESS -> conversion process was succeded
*/ 
void* fe_automatic_handler(void* base,void* dependent) {
    if (!base || !dependent)
        return NULL_ARGUMENT_ERROR;
    
    //converting stuff...
}

/*
Updates Fe_String Struct properties such as:
Length -> len().
*/ 
void fe_update_string(fe_string* str) {
    char* string_content = str->str_ref;
    str->len = strlen(string_content);
}