#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <wchar.h>
#include "feerror.h"
#include "fetypes.h"


int int10_to_ascii(int num,const char* ascii_ref) {
    char ascii_char;

    int bin_shifted = 3 << 4;
    int num_ref = num | bin_shifted;
    int error = int_to_char_ascii(num_ref,&ascii_char);

    if (error == CAST_CONVERSION_ERROR || error == NULL_ARGUMENT_ERROR)
        return error;
    
    ascii_ref = &ascii_char;
    return CONVERSION_SUCCESS;
}

int wchart_to_char(const wchar_t* from,const char* to) {
    int from_size = sizeof(from) + 1;
    char* cfrom;
    wcstombs(cfrom,from,from_size);
    if (!cfrom) {
        return CONVERSION_ERROR;
    }
    to = cfrom;
    return CONVERSION_SUCCESS;
}

int get_int_numerals(int value, int numerals[24]) {
    int ammount_of_reps = (log10f(value));
}

int char_to_wchart(const char* from, const wchar_t* to) {
    int from_size = sizeof(from) + 1;

    wchar_t* wfrom;
    mbstowcs(wfrom,from,from_size);
    if (!wfrom) {
        return CONVERSION_ERROR;
    }
    to = wfrom;
    return CONVERSION_SUCCESS;
}

//only for joining strs
void concat2(const char* str1, const char* str2,const char** strend) {
    int strsize = sizeof(str1) + sizeof(str2) + 1;
    char cc[strsize];
    snprintf(cc,strsize,"%s%s",str1,str2);
    *strend = cc;
}

/*
applies color to text, (all of them needs to be a char*)
bold: 1 or 0,
color: can be anything that is a ansii escape code (\033[1;31m)
*/
void apply_color(const char* text,const char* color_code,const char* bold,const char** color_escape_end) {
    int size = strlen(text) + strlen(color_code) + 14; //7 (\033[;m) + 7 (\033[0m)
    char buffer[size];

    snprintf(
        buffer,
        size,
        "\033[%s;%sm%s\033[0m",
        color_code,
        bold,
        text
    );

    *color_escape_end = buffer;
}
//\033[1;31m 