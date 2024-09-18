#include <cstddef>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "args_proc.h"


int main(const int argc, const char *argv[]) {

    opt_data* opts[] = {
                        opt_data_constructor("-u", "--unit", 1, unit_function),
                        opt_data_constructor("-t", "--utesting", 2, testing_function),
                        opt_data_constructor("-h", "--help", 0, help_function),
                        };
    opts[0]->exist = true;
    opts[1]->exist = true;
    opts[2]->exist = true;
    // FIXME: Почему нет memory leaks, я же не вызываю opt_data_destructor. память остается алоцированной
    // TODO:  Как парсить аргументы командной строки??
    err_code LastErr = ERR_OK;
    mode_manager(opts, 1, &LastErr);
    return 0;
}