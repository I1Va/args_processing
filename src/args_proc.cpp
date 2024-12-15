#include <cstddef>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>

#include "args_err_proc.h"
#include "args_proc.h"
#include "general.h"

opt_data *option_list_ptr(const char *name, opt_data opts[], const size_t n_opts) {
    for (size_t i = 0; i < n_opts; i++) {
        if (strcmp(name, opts[i].short_name) == 0 || strcmp(name, opts[i].long_name) == 0) {
            return &opts[i];
        }
    }
    return NULL;
}

void get_options(const int argc, const char* argv[], opt_data opts[], const size_t n_opts) {
    assert(argc >= 0);

    for (int i = 1; i < argc; i++) {
        char name[MAX_OPT_NAME_SZ];
        char value[MAX_OPT_NAME_SZ];
        sscanf(argv[i], "%[^=]%s", name, value);

        opt_data *ptr = option_list_ptr(name, opts, n_opts);

        if (ptr != NULL) {
            sscanf(value + 1, (ptr->fmt), ptr->val_ptr); // FIXME: исправить warning. Мб использовать __atribute__
            ptr->exist = true;
        }
    }
}

// // MODES/CONFIG ZONE

void example_config_print(FILE *stream, example_config_t *conf) {
    fprintf_red(stream, RED "example_config_t: \n");
    fprintf(stream, "conf_coeff: %f\n", conf->coeff);
    fprintf(stream, "conf_name: %s\n", conf->name);
    fprintf(stream, "conf_coeff: %lld\n", conf->value);
    fprintf(stream, "conf_coeff: %d\n", conf->n);
}
