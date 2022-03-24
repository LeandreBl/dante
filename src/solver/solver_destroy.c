#include "solver.h"

void solver_destroy(struct dante_solver *solver)
{
    maze_destroy(&solver->maze);
    lvector_destroy(solver->previous_positions);
}