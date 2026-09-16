#ifndef FERTH_PRIMITIVE_TYPES
#define FERTH_PRIMITIVE_TYPES
#define FE_AUTO(x) fe_automatic_handler(x)
#endif

#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include "feerror.h"

//Types Def

struct fe_string {
    const char* str_ref;
    uint32_t len;
};

struct fe_number {
    double num_ref;
};

struct fe_file {
    FILE* fileobj;
    const char* filepath;
};


//Type util Def
//

// int conversions

int inttofloat(int value, float** return_val) {
    float* converted = (float*)*return_val;
    if (!converted) {
        return CAST_CONVERSION_ERROR;
    }
    *return_val = converted;
    return CAST_CONVERSION_SUCCESS;
}


void* fe_automatic_handler() {

}

void fe_update_string(struct fe_string* str) {
    const char* string_content = str->str_ref;
    str->len = sizeof(string_content) / 8;
}