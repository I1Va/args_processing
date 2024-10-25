#ifndef ARGS_ERR_PROC_H
#define ARGS_ERR_PROC_H

#include "general.h"

#define ASSERT(error, end_instruction)                                                                                    \
    fprintf_red(stderr, "{%s} [%s: %d]: descr{%s}\n", __FILE_NAME__, __PRETTY_FUNCTION__, __LINE__, get_descr(error));    \
    end_instruction;

enum arg_err_code {
    ARG_ERR_OK = 0,
    ARG_ERR_NULLPTR = 1, // TODO: подравняй нумерацию
    ARG_ERR_CALLOC = 2,
    ARG_ERR_MEM = 3,
    ARG_ERR_UNKNOWN = 4,
    ARG_ERR_STAT = 5,
    ARG_ERR_INPUT_DATA = 6,
    ARG_ERR_FILE_OPEN = 7,
    ARG_ERR_FILE_CLOSE = 8,
    ARG_ERR_ARGS = 9,
    ARG_ERR_ARG_NOT_EXIST = 10,
};

const char *get_descr(enum arg_err_code err);

#endif // ARGS_ERR_PROC_H