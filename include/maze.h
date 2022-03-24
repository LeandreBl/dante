#ifndef MAZE_H
#define MAZE_H

#include <lstr.h>
#include <lvector.h>

#include "cell.h"
#include "vector2.h"

typedef lvector(struct vector2) positions_t;
typedef lvector(enum CELL_TYPE) maze_line_t;
typedef lvector(maze_line_t) maze_column_t;

struct maze {
    lstr_t filename;
    maze_column_t matrix;
    maze_column_t solved_matrix;
};

int maze_create(struct maze *maze, const lstr_t *filename);
void maze_destroy(struct maze *maze);

int maze_set_celltype(struct maze *maze, struct vector2 position, enum CELL_TYPE type);
bool maze_is_celltype(const struct maze *maze, struct vector2 position,
                      enum CELL_TYPE type);
bool maze_is_empty(const struct maze *maze, struct vector2 position);
bool maze_is_out_of_bound(const struct maze *maze, struct vector2 position);
int maze_get_possible_next_moves(const struct maze *maze, struct vector2 at,
                                 positions_t *positions);
void maze_fill_solved_matrix(struct maze *maze, const positions_t *positions);

#endif