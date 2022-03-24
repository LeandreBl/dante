#ifndef DANTE_H
#define DANTE_H

#include <lstr.h>

#include "maze.h"

struct dante_solver {
    struct maze maze;
    struct vector2 actual_position;
    positions_t previous_positions;
    struct vector2 end_position;
};

int solver_create(struct dante_solver *solver, const lstr_t *filename);
void solver_destroy(struct dante_solver *solver);

int solver_backtrack(struct dante_solver *solver);
int solver_run(struct dante_solver *solver);
int solver_move(struct dante_solver *solver, struct vector2 at);
void solver_display(const struct dante_solver *solver);

#endif