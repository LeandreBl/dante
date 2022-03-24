#include "maze.h"

void maze_destroy(struct maze *maze)
{
    lstr_destroy(&maze->filename);
    lvector_destroy(maze->matrix);
    lvector_destroy(maze->solved_matrix);
}