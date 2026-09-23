#ifndef FERTH_PRIMITIVE_TYPES
#define FERTH_PRIMITIVE_TYPES
#define FE_AUTO(x) fe_automatic_handler(x)
#define FE_NUMBER_DB(name,value) fe_number name = {.int_ref = value}

#include <stdint.h>

//Types Def

/*
Ferth String, struct that supports string manipulation
*/
struct fe_string { //fe string
    char* str_ref;
    uint32_t len;
} ;

/*
Ferth Number, struct that supports both int and float
*/
struct fe_number { 
    uint32_t int_ref;
    uint32_t dec_ref;
    int signal;
    void (*to_str)();
};

typedef struct fe_string fe_string;

typedef struct fe_number fe_number;


int charp_to_fe_string(const char* value, fe_string* return_val);

int fe_string_to_charp(fe_string value, const char** return_value);

int int_to_charp(int value, const char** return_val);

int char_to_int(char value,int* return_val);

int int_to_char_ascii(int value, const char* return_val);

int fe_num_to_int(fe_number value, int* return_value);

int fe_num_to_float(fe_number value,float* return_value);

int fe_num_to_double(fe_number value,double* return_value);

void fe_update_string(fe_string* str);

void* fe_automatic_handler();

#endif