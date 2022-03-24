#include "maze.h"

void maze_fill_solved_matrix(struct maze *maze, const positions_t *cpositions)
{
    positions_t *positions = (typeof(positions))cpositions;
    lvector_foreach(cell, *positions) {
        maze->solved_matrix.arr[cell->y].arr[cell->x] = PASSED;
    }
}