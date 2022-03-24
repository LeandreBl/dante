#include <stdio.h>

#include "solver.h"

void solver_display(const struct dante_solver *solver)
{
    maze_column_t *matrix = (typeof(matrix))&solver->maze.solved_matrix;
    lvector_foreach(line, *matrix) {
        lvector_foreach(cell, *line) {
            printf("%c", *cell);
        }
        printf("\n");
    }
}