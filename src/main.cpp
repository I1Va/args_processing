#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "err_proc.h"
#include "args_proc.h"
#include "conf_ctor.h"


int main(const int argc, const char *argv[]) {
    testing_config *testing_data = testing_config_ctor();
    main_config *main_data = main_config_ctor();
    help_config *help_data = help_config_ctor();


    opt_data *options[] =
    {
        opt_data_constructor("-t", "--testing@name", "%s", testing_data->name),
        opt_data_constructor("-u", "--main@mega_size", "%ld", &main_data->mega_size),
        opt_data_constructor("-h", "--help@glombik", "%lg", &help_data->glombik),
    };

    const size_t n_options = sizeof(options) / sizeof(opt_data *);

    get_options(argc, argv, options, n_options);

    printf("name: %s\n", testing_data->name);
    printf("glomb: %f\n", help_data->glombik);
    printf("name: %ld\n", main_data->mega_size);
}