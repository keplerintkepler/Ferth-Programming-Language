#include <stdio.h>
#include <stdint.h>
#include <float.h>

#include "feerror.h"
#include "feconstants.h"
#include "feutils.h"


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
        return "ConversionError";

        default:
        return "INVALIDERRORNAME";
    }
}

char* fe_error_log(int error_code,FILE* file) {
    char* firstline = "fe compiler error:\n";
    char* secondline =  "file: ";

    char* filepath = 
    char* error_name = fe_error_name(error_code);
    return "";
}