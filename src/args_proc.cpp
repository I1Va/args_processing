#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "general.h"
#include "err_proc.h"
#include "args_proc.h"

void testing_function(const char *parse_bufer, err_code *ReturnErr) {
    printf("testing function: %s\n", parse_bufer);
    *ReturnErr = ERR_MEM;
    return;
}
void unit_function(const char *parse_bufer, err_code *ReturnErr) {
    printf("unit function: %s\n", parse_bufer);
    *ReturnErr = ERR_MEM;
    return;
}
void help_function(const char *parse_bufer, err_code *ReturnErr) {
    printf("help function: %s\n", parse_bufer);
    *ReturnErr = ERR_MEM;
    return;
}

opt_data *opt_data_constructor(const char *const short_name_src, const char *const long_name_src,
     const size_t n_args, void (*launch_function)(const char* parse_bufer, err_code *ReturnErr)) {

    opt_data *option = (opt_data *) calloc(1, sizeof(opt_data));
    if (option == NULL) {
        ASSERT(ERR_CALLOC, return NULL)
    }

    const size_t short_sz = strlen(short_name_src);
    const size_t long_sz = strlen(long_name_src);

    option->short_name = (char *) calloc(short_sz + 1, sizeof(char));
    if (option->short_name == NULL) {
        ASSERT(ERR_CALLOC, goto END_POINT_0)
    }

    option->long_name = (char *) calloc(long_sz + 1, sizeof(char));
    if (option->long_name == NULL) {
        ASSERT(ERR_CALLOC, goto END_POINT_1)
    }

    strcpy(option->long_name, long_name_src);
    strcpy(option->short_name, short_name_src);

    option->n_args = n_args;
    option->parse_bufer = NULL;
    option->exist = false;
    option->launch_function = launch_function;

    return option;

    END_POINT_1:
    FREE(option->short_name)
    END_POINT_0:
    FREE(option)

    return NULL;
}

void opt_data_destructor(opt_data *option) {
    FREE(option->short_name);
    FREE(option->short_name);
    FREE(option);
}

void mode_manager(opt_data *options[], const size_t n, err_code *ReturnErr) {
    err_code LastErr = ERR_OK;

    for (size_t i = 0; i < n; i++) {
        if (options[i]->exist) {
            options[i]->launch_function(options[i]->parse_bufer, &LastErr);

            if (LastErr != ERR_OK) {
                *ReturnErr = LastErr;
                ASSERT(LastErr, return)
            }
        }
    }
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

    for (int i = 0; i < argc; i++) {
        opt_data *ptr = option_list_ptr(argv[i], opts, n_opts);
        if (ptr == NULL) {

        }
        ptr->exist = true;
        if ((size_t) i + ptr->n_args < (size_t) argc) {

        }
    }
}