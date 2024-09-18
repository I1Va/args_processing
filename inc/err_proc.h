#ifndef ERR_PROC_H
#define ERR_PROC_H

#include <stdio.h>
#include <string.h>
#include "general.h"

#define ASSERT(error, end_instruction)                                                                                    \
    fprintf_red(stderr, "{%s} [%s: %d]: descr{%s}\n", __FILE_NAME__, __PRETTY_FUNCTION__, __LINE__, get_descr(error));    \
    end_instruction;

enum err_code {
    ERR_OK = 0,
    ERR_NULLPTR = 1, // TODO: подравняй нумерацию
    ERR_CALLOC = 2,
    ERR_MEM = 3,
    ERR_UNKNOWN = 4,
    ERR_STAT = 5,
    ERR_INPUT_DATA = 6,
    ERR_FILE_OPEN = 7,
    ERR_FILE_CLOSE = 8,
    ERR_ARGS = 9,
    ERR_ARG_NOT_EXIST = 10,
};

const char *get_descr(enum err_code err);

#endif // ERR_PROC_H