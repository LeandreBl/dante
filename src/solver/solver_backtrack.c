#include "solver.h"

int solver_backtrack(struct dante_solver *solver)
{
    struct vector2 pos;

    if (solver->previous_positions.len == 0) {
        return 0;
    }
    if (solver_move(solver, solver->actual_position) == -1)
        return -1;
    pos = *lvector_back(solver->previous_positions);
    lvector_pop_back(solver->previous_positions);
    solver->actual_position = pos;
    return 0;
}