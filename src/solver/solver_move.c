#include "solver.h"

int solver_move(struct dante_solver *solver, struct vector2 at)
{
    if (maze_is_empty(&solver->maze, at) == false)
        return 1;
    lvector_push_back(solver->previous_positions, solver->actual_position);
    if (maze_set_celltype(&solver->maze, solver->actual_position, PASSED) == -1)
        return -1;
    solver->actual_position = at;
    return 0;
}