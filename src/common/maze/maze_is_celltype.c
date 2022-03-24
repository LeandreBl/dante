#include "maze.h"

bool maze_is_celltype(const struct maze *maze, struct vector2 position, enum CELL_TYPE type)
{
    if (maze_is_out_of_bound(maze, position) == true) {
        return false;
    }
    return maze->matrix.arr[position.y].arr[position.x] == type;
}