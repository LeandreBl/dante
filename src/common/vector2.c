#include "vector2.h"

struct vector2 vector2_create(int x, int y)
{
    return (struct vector2){.x = x, .y = y};
}

bool vector2_is_equal(struct vector2 a, struct vector2 b)
{
    return a.x == b.x && a.y == b.y;
}