#include "maze.h"

static const struct vector2 MOVES_MATRIX[] = {
    {.x = 0, .y = -1},
    {.x = -1, .y = 0},
    {.x = 0, .y = 1},
    {.x = 1, .y = 0},
};

int maze_get_possible_next_moves(const struct maze *maze, struct vector2 at,
                                 positions_t *positions)
{
    struct vector2 pos;
    lvector_clear(*positions);
    if (maze_is_out_of_bound(maze, at) == true)
        return 0;
    for (size_t i = 0; i < sizeof(MOVES_MATRIX) / sizeof(*MOVES_MATRIX); ++i) {
        pos = vector2_create(MOVES_MATRIX[i].x + at.x, MOVES_MATRIX[i].y + at.y);
        if (maze_is_empty(maze, pos) == true)
            lvector_push_back(*positions, pos);
    }
    return 0;
}