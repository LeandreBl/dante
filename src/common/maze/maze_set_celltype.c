#include "maze.h"

int maze_set_celltype(struct maze *maze, struct vector2 position, enum CELL_TYPE type)
{
    if (maze_is_out_of_bound(maze, position) == true)
        return 1;
    maze->matrix.arr[position.y].arr[position.x] = type;
    return 0;
}
