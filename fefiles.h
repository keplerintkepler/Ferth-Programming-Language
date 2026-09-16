#ifndef FERTH_FILE_LIB
#define FERTH_FILE_LIB
#endif

#define OPEN_FILE(p,f) open_file(p,f)
#define FILE_TEXT(f,c) get_file_text(f,c)
#define CREATE_FILE(p,f) create_file(p,f)
#define WRITE_TEXT_FILE(c,f) write_file_text(c,f)
#define CLOSE_FILE(f) create_file(f)

int open_file(const char* file_path, FILE** file);

int get_file_text(FILE* file,const char** content);

int create_file(const char* file_path, FILE** file_result);

int write_file_text( const char* content, FILE** file_result);

int close_file(FILE* file);