#ifndef ARGS_PROC_H
#define ARGS_PROC_H

#include <string.h>

struct opt_data {
    const char *short_name;
    const char *long_name;

    const char *fmt;
    void *val_ptr;

    bool exist;
};

const size_t MAX_OPT_NAME_SZ = 64;
const size_t MAX_CONFIG_NAME_SIZE = 64;

void opt_data_ctor(opt_data *option, const char *const short_name_src, const char *const long_name_src,
    const char *const fmt_src, void *val_ptr_src);

void opt_data_dtor(opt_data *option);

opt_data *option_list_ptr(const char *name, opt_data opts[], const size_t n_opts);

void get_options(const int argc, const char* argv[], opt_data opts[], const size_t n_opts);

// MODES/CONFIG ZONE

struct example_config_t {
    bool exist;
    char name[MAX_CONFIG_NAME_SIZE];
    long long value;
    double coeff;
    int n;
};

void example_config_ctor(example_config_t *conf);

void example_config_dtor(example_config_t *conf);

void example_config_print(example_config_t *conf);

#endif // ARGS_PROC_H