#ifndef FERTH_FILES
#define FERTH_FILES

#define FERTHFILE fe_file

#define OPEN_FILE(p,f) open_file(p,f)
#define FILE_TEXT(f,c) get_file_text(f,c)
#define CREATE_FILE(p,f) create_file(p,f)
#define WRITE_TEXT_FILE(c,f) write_file_text(c,f)
#define CLOSE_FILE(f) create_file(f)


//Improved FileObject with PATH
typedef struct {
    FILE* fileobj; //File Object Inside (Equivalent to FILE*)
    char* filepath; //Current File Path, given in CREATE_FILE macro func
    char* absolute_path; //Absolute filepath, like C:/Users/Kplr/Documents/file.fe
} fe_file;


int open_file(char* file_path, fe_file* file);

int get_file_text(fe_file file,char** content);

int create_file(char* file_path, fe_file* file_result);

int write_file_text(char* content, fe_file* file_result);

int close_file(fe_file file);

#endif