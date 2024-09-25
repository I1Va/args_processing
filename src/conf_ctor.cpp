#include "conf_ctor.h"
#include "err_proc.h"
#include <cstdlib>

const size_t testing_config_name_sz = 100;

testing_config *testing_config_ctor() {
    testing_config *conf = (testing_config *) calloc(1, sizeof(testing_config));
    if (conf == NULL) {
        DEBUG_ERROR(ERR_CALLOC);
        CLEAR_MEMORY(exit_mark);
    }

    conf->name = (char *) calloc(testing_config_name_sz, sizeof(char));
    if (conf->name == NULL) {
        DEBUG_ERROR(ERR_CALLOC);
        CLEAR_MEMORY(exit_mark);
    }

    conf->n_tests = 0;

    return conf;

    exit_mark:

    if (conf != NULL) {
        FREE(conf)
    }
    if (conf->name != NULL) {
        FREE(conf->name)
    }

    return NULL;
}

void testing_config_dtor(testing_config *conf) {
    FREE(conf->name)
    FREE(conf)
}

help_config *help_config_ctor() {
    help_config *conf = (help_config *) calloc(1, sizeof(help_config));
    if (conf == NULL) {
        DEBUG_ERROR(ERR_CALLOC);
        CLEAR_MEMORY(exit_mark);
    }
    conf->glombik = 0;

    return conf;

    exit_mark:

    if (conf != NULL) {
        FREE(conf)
    }

    return NULL;
}

void help_config_dtor(help_config *conf) {
    FREE(conf)
}

main_config *main_config_ctor() {
    main_config *conf = (main_config *) calloc(1, sizeof(main_config));
    if (conf == NULL) {
        DEBUG_ERROR(ERR_CALLOC);
        CLEAR_MEMORY(exit_mark);
    }
    conf->mega_size = 0;

    return conf;

    exit_mark:

    if (conf != NULL) {
        FREE(conf)
    }

    return NULL;
}

void main_config_dtor(main_config *conf) {
    FREE(conf);
}

