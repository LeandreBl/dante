#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdbool.h>
#include <stddef.h>

struct vector2 {
    int x;
    int y;
};

struct vector2 vector2_create(int x, int y);
bool vector2_is_equal(struct vector2 a, struct vector2 b);

#endif