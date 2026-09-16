#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
    /*char* line1 = "fe compiler error.\n";
    char* line2 = "\033[1;96mfile : \"C:\\Users\\user1\\Downloads\\app.fe\" in (row:5, col:54) inside scope \"global\":\033[m\n\n";
    char* line3 = "\033[1;31mintr\033[m x = 2\n\033[1;31m^^^^\033[m\n\n";
    char* line4 = "\033[1;96undefined object reference -> identifier \"intr\" is undefined.\n did you mean \"int\"?\n\033[m";
    
    printf(line1);
    printf(line2);
    printf(line3);
    printf(line4);*/
    printf("fe compiler error.\n \033[1;96m file : \"C:\\Users\\user1\\Downloads\\app.fe\" in (row:5, col:54) inside scope \"global\": \033[m \n\n \033[1;31m intr \033[m x = 2\n \033[1;31m ^^^^ \033[m \n\n \033[1;96m undefined object reference -> identifier \"intr\" is undefined. did you mean \"int\"?\n \033[m ");
    Sleep(5000);
    return 0;
}