#ifndef CONF_CTOR_H
#define CONF_CTOR_H

struct testing_config {
    char *name;
    int n_tests;
};

struct help_config {
    double glombik;
};

struct main_config {
    long mega_size;
};


testing_config *testing_config_ctor();

void testing_config_dtor(testing_config *conf);

help_config *help_config_ctor();

void help_config_dtor(help_config *conf);

main_config *main_config_ctor();

void main_config_dtor(main_config *conf);


#endif // CONF_CTOR_H