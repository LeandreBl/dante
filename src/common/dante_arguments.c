#include "dante_arguments.h"

int solver_arguments_create(struct solver_arguments *arguments)
{
    if (lstr_create(&arguments->filename, "") == -1) {
        return -1;
    }
    return 0;
}

void solver_arguments_destroy(struct solver_arguments *arguments)
{
    lstr_destroy(&arguments->filename);
}