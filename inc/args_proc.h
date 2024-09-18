#ifndef ARGS_PROC_H
#define ARGS_PROC_H
#include "err_proc.h"


struct opt_data {
    char *short_name;
    char *long_name;

    size_t n_args;

    char *parse_bufer;
    bool exist;
    void (*launch_function)(const char* parse_bufer, err_code *ReturnErr);
};

void testing_function(const char *parse_bufer, err_code *ReturnErr);

void unit_function(const char *parse_bufer, err_code *ReturnErr);

void help_function(const char *parse_bufer, err_code *ReturnErr);

opt_data *opt_data_constructor(const char *const short_name_src, const char *const long_name_src,
     const size_t n_args, void (*launch_function)(const char* parse_bufer, err_code *ReturnErr));

void opt_data_destructor(opt_data *option);

void mode_manager(opt_data *options[], const size_t n, err_code *ReturnErr);

opt_data *option_list_ptr(const char *name, opt_data *opts[], const size_t n_opts);

void get_options(const int argc, const char* argv[], opt_data *opts[], const size_t n_opts);

#endif // ARGS_PROC_H