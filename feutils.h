#ifndef FERTH_UTILS
#define FERTH_UTILS
#endif

#define C_CONCAT(str1,str2) concat(str1,str2)


char* concat(const char* str1, const char* str2);

char* apply_color(char* text,int color_code,int bold);