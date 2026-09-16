#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "feerror.h"

//only for joining strs
char* concat(const char* str1, const char* str2) {
    char* isconcat = malloc(strlen(str1) + strlen(str2) + 1);
    if (isconcat == NULL) isconcat = NULL;
    strcpy(isconcat,str1);
    strcat(isconcat,str2);
    return isconcat;
}

/*
applies color to text, (all of them needs to be a char*)
bold: 1 or 0,
color: can be anything that is a ansii escape code
*/
char* apply_color(char* text,char* color_code,char* bold) {
    char* line1 = concat("\033[",bold);

    char* line2 = concat(line1,color_code);
    free(line1);

    line1 = concat(line2,";");
    free(line2);

    line2 = concat(line1,color_code);
    free(line1);

    line1 = concat(line2,"m");
    free(line2);

    return line1;
}