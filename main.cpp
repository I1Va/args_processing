#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "args_proc.h"

int main(const int argc, const char *argv[]) {
    example_config_t example_config = {};

    opt_data options[] =
    {
        {"-e-name", "--example-name", "%s", &example_config.name},
        {"-e-value", "--example-value", "%lld", &example_config.value},
        {"-e-coeff", "--example-coeff", "%lf", &example_config.coeff},
        {"-e-n", "--example-n", "%d", &example_config.n},
    };

    size_t n_options = sizeof(options) / sizeof(opt_data);

    get_options(argc, argv, options, n_options);

    example_config_print(&example_config);

    return EXIT_SUCCESS;
}
