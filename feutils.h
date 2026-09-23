#ifndef FERTH_UTILS
#define FERTH_UTILS

#define WCHART_TO_CHAR(from,to) wchart_to_char(from,to)
#define CHAR_TO_WCHART(from,to) char_to_wchart(from,to)

#define C_CONCAT(str1,str2,strend) concat2(str1,str2,strend)
#define APPLY_COLOR(text,color_code,bold,endval) apply_color(text,color_code,bold,endval)

int wchart_to_char(const wchar_t* from, const char* to);

int char_to_wchart(const char* from, const wchar_t* to);



void concat2(const char* str1, const char* str2,const char** strend);

void apply_color(const char* text,const char* color_code,const char* bold,const char** color_escape_end);

#endif