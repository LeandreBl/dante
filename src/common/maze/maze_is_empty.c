#include "maze.h"

bool maze_is_empty(const struct maze *maze, struct vector2 position)
{
    return maze_is_celltype(maze, position, EMPTY);
}