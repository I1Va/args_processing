#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "general.h"
#include "err_proc.h"
#include "args_proc.h"

opt_data *opt_data_constructor(const char *const short_name_src, const char *const long_name_src,
    const char *const fmt_src, void *val_ptr_src) {

    opt_data *option = (opt_data *) calloc(1, sizeof(opt_data));
    if (option == NULL) {
        ASSERT(ERR_CALLOC, return NULL)
    }

    const size_t short_sz = strlen(short_name_src);
    const size_t long_sz = strlen(long_name_src);
    const size_t fmt_sz = strlen(fmt_src);

    option->short_name = (char *) calloc(short_sz + 1, sizeof(char));
    if (option->short_name == NULL) {
        DEBUG_ERROR(ERR_CALLOC)
        CLEAR_MEMORY(exit_mark)
    }

    option->long_name = (char *) calloc(long_sz + 1, sizeof(char));
    if (option->long_name == NULL) {
        DEBUG_ERROR(ERR_CALLOC)
        CLEAR_MEMORY(exit_mark)
    }

    option->fmt = (char *) calloc(fmt_sz + 1, sizeof(char));
    if (option->fmt == NULL) {
        DEBUG_ERROR(ERR_CALLOC)
        CLEAR_MEMORY(exit_mark)
    }

    option->val_ptr = val_ptr_src;

    option->exist = false;

    strcpy(option->long_name, long_name_src);
    strcpy(option->short_name, short_name_src);
    strcpy(option->fmt, fmt_src);


    return option;

    exit_mark:
    if (option != NULL) {
        FREE(option)
    }

    if (option->short_name != NULL) {
        FREE(option->short_name)
    }

    if (option->long_name != NULL) {
        FREE(option->long_name)
    }

    if (option->fmt != NULL) {
        FREE(option->fmt)
    }

    return NULL;
}

void opt_data_destructor(opt_data *option) {
    FREE(option->short_name);
    FREE(option->short_name);
    FREE(option);
}

opt_data *option_list_ptr(const char *name, opt_data *opts[], const size_t n_opts) {
    for (size_t i = 0; i < n_opts; i++) {
        if (strcmp(name, opts[i]->short_name) == 0 || strcmp(name, opts[i]->long_name) == 0) {
            return opts[i];
        }
    }
    return NULL;
}

void get_options(const int argc, const char* argv[], opt_data *opts[], const size_t n_opts) {
    assert(argc >= 0);

    for (int i = 1; i < argc; i++) {
        char *name = (char *) calloc(strlen(argv[i]), sizeof(char)); // FIXME: заменить на статические переменные
        char *value = (char *) calloc(strlen(argv[i]), sizeof(char));

        sscanf(argv[i], "%[^=]%s", name, value);

        opt_data *ptr = option_list_ptr(name, opts, n_opts);

        if (ptr != NULL) {
            ptr->exist = true;

            sscanf(value + 1, (ptr->fmt), ptr->val_ptr);
        }

        FREE(name)
        FREE(value)
    }
}
