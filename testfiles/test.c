
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** args)
{
    char* arg1 = args[1];
    char* arg2 = args[2];
    printf(arg1);
    printf(arg2);
    char* gg = malloc(sizeof(arg1) + sizeof(arg2) + 1);
    gg = strcpy(arg1,arg2);
    printf(gg);

    free(gg);
    return 0;
}