#ifndef DANTE_ARGUMENTS_H
#define DANTE_ARGUMENTS_H

#include <lstr.h>

struct solver_arguments {
    lstr_t filename;
};

int solver_arguments_create(struct solver_arguments *arguments);
void solver_arguments_destroy(struct solver_arguments *arguments);

#endif