#ifndef ARGS_PROC_H
#define ARGS_PROC_H

#include <string.h>

struct opt_data {
    char *short_name;
    char *long_name;

    bool exist;

    char *fmt;
    void *val_ptr;
};


opt_data *opt_data_constructor(const char *const short_name_src, const char *const long_name_src,
    const char *const fmt_src, void *val_ptr_src);

void opt_data_destructor(opt_data *option);

opt_data *option_list_ptr(const char *name, opt_data *opts[], const size_t n_opts);

void get_options(const int argc, const char* argv[], opt_data *opts[], const size_t n_opts);


#endif // ARGS_PROC_H