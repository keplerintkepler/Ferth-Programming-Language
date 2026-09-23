#include <stdio.h>
#include <stdint.h>
#include <float.h>

#include "feerror.h"
#include "feconstants.h"
#include "feutils.h"
#include "fefiles.h"

char* fe_error_name(int error_code) {
    switch (error_code) {
        case MEMORY_ALLOC_ERROR:
        return "MemoryAllocationError";
        
        case NULL_PATH_ERROR:
        return "NullPathError";

        case FILE_PATH_ERROR:
        return "InvalidFilePathError";

        case NULL_FILE_ERROR:
        return "NullFileError";

        case OPEN_FILE_ERROR:
        return "OpenFileError";

        case CREATE_FILE_ERROR:
        return "FileCreationError";

        case NULL_ARGUMENT_ERROR:
        return "NullArgumentError";

        case INVALID_ARGUMENT_ERROR:
        return "InvalidArgumentError";

        case CAST_CONVERSION_ERROR:
        return "CastConversionError";

        case CONVERSION_ERROR:
        return "ConversionError";

        case FETCH_ERROR:
        return "FetchError";

        default:
        return "INVALIDERRORNAME";
    }
}

void fe_file_error_log(int error_code,fe_error_info info,char** final_error_log) {
    char* firstline = "fe compiler error:\n";
    char* secondline =  "file: ";
    char* thirdline = "bb\n";
    char* forthline = "gg\n";

    char* error_name = fe_error_name(error_code);
    char* filepath = info.error_file.filepath;
    char* nwsec;
    snprintf(
        secondline,
        sizeof(secondline) + sizeof(filepath) + 1,
        "%s%s%c",
        secondline,
        filepath,
        '\n'
    );

    apply_color(secondline,"96","1",&nwsec); //secondline is always turquoise

    snprintf(
        *final_error_log,
        512,
        "%s%s%s%s",
        firstline,
        secondline,
        thirdline,
        forthline
    );
}

/*int main() {
    //printf("helo!\n\n");

    fe_file curfile;
    OPEN_FILE("testfiles\\testfile.fe",&curfile);
    printf("%s",curfile.filepath);

    fe_error_info info = {
        curfile,
        "2",
        "56",
        "MAIN",
        NULL,
        NULL,
        NULL,
        NULL,
    };
    char* log;
    FILE_ERROR_LOG(OPEN_FILE_ERROR,info,&log);
    printf(log);
}*/