

#include "args_err_proc.h"


#define DESCR_(code) case code : return #code;

const char *get_descr(enum arg_err_code err) {
    switch (err) {
        DESCR_(ARG_ERR_OK)
        DESCR_(ARG_ERR_UNKNOWN)
        DESCR_(ARG_ERR_CALLOC)
        DESCR_(ARG_ERR_NULLPTR)
        DESCR_(ARG_ERR_STAT)
        DESCR_(ARG_ERR_INPUT_DATA)
        DESCR_(ARG_ERR_MEM)
        DESCR_(ARG_ERR_FILE_CLOSE)
        DESCR_(ARG_ERR_FILE_OPEN)
        DESCR_(ARG_ERR_ARGS)
        DESCR_(ARG_ERR_ARG_NOT_EXIST)
        default: return "VERY STRANGE ERROR:(";
    }
}
#undef DESCR_