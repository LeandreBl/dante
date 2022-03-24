#include "solver.h"

int solver_create(struct dante_solver *solver, const lstr_t *filename)
{
    size_t height;

    if (maze_create(&solver->maze, filename) == -1)
        return -1;
    height = solver->maze.matrix.size;
    solver->actual_position = vector2_create(0, 0);
    lvector_create(solver->previous_positions, solver->maze.matrix.size, NULL);
    solver->end_position = vector2_create(solver->maze.matrix.arr[height - 1].size - 1, height - 1);
    return 0;
}