#include "maze.h"

bool maze_is_out_of_bound(const struct maze *maze, struct vector2 position)
{
    return position.x < 0 || position.y < 0 || (size_t)position.y >= maze->matrix.len || (size_t)position.x >= maze->matrix.arr[position.y].len;
}