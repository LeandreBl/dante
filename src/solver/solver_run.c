#include "solver.h"

int solver_run(struct dante_solver *solver)
{
    positions_t next_moves;
    struct vector2 move;

    lvector_create(next_moves, 4, NULL);
    while (!vector2_is_equal(solver->actual_position, solver->end_position)) {
        if (maze_get_possible_next_moves(&solver->maze, solver->actual_position, &next_moves) == -1) {
            return -1;
        }
        if (next_moves.len == 0) {
            if (solver->previous_positions.len == 0) {
                lvector_destroy(next_moves);
                return 1;
            }
            if (solver_backtrack(solver) == -1) {
                return -1;
            }
            continue;
        }
        move = next_moves.arr[0];
        if (solver_move(solver, move) == -1) {
            return -1;
        }
    }
    if (solver_move(solver, solver->actual_position) == -1) {
        return -1;
    }
    maze_fill_solved_matrix(&solver->maze, &solver->previous_positions);
    lvector_destroy(next_moves);
    return 0;
}