#ifndef FERTH_PRIMITIVE_TYPES
#define FERTH_PRIMITIVE_TYPES
#define FE_AUTO(x) fe_automatic_handler(x)
#endif

#define NULL_ARGUMENT_ERROR 0x6F0
#define INVALID_ARGUMENT_ERROR 0x6F1
#define CAST_CONVERSION_ERROR 0x6F2

#include <stdio.h>
#include <stdint.h>
#include <float.h>

//Types Def

struct fe_string {
    const char* str_ref;
    uint32_t len;
};

struct fe_number {
    double num_ref;
};


//Type util Def

int toint(void* value, int* return_int) {
    
}

void* fe_automatic_handler() {

}

void fe_update_string(struct fe_string* str) {
    const char* string_content = str->str_ref;
    str->len = sizeof(string_content) / 8;
}