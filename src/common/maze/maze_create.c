#include <stdio.h>
#include <errno.h>

#include "maze.h"
#include "logs.h"

static int fill_line(maze_line_t *line, const char *str, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        switch (str[i])
        {
        case WALL:
        /* implicit fallthrough */
        case EMPTY:
            lvector_push_back(*line, str[i]);
            break;
        default:
            logs_error("Error: '%c' character is invalid\n", str[i]);
            return -1;
        }
    }
    return 0;
}

static int load_one_line(maze_column_t *column, FILE *f)
{
    char *str = NULL;
    size_t n = 0;
    ssize_t status;
    size_t length;

    status = getline(&str, &n, f);
    if (status == -1) {
        free(str);
        return errno != 0 ? -1 : 1;
    }
    length = (size_t)status;
    if (length == 0) {
        logs_error("Error: empty line found in file\n");
        return -1;
    }
    if (str[length - 1] == '\n') {
        --length;
    }
    lvector_resize(*column, (column->size + 1));
    ++column->size;
    lvector_create(*lvector_back(*column), length, NULL);
    if (fill_line(lvector_back(*column), str, length) == -1) {
        free(str);
        return -1;
    }
    free(str);
    return 0;
}

static int load_maze_lines(struct maze *maze)
{
    FILE *f = fopen(maze->filename.i, "r");
    int status;

    if (f == NULL) {
        return -1;
    }
    do {
        status = load_one_line(&maze->matrix, f);
    } while (status == 0);
    if (fseek(f, 0, SEEK_SET) == -1) {
        fclose(f);
        return -1;
    }
    do {
        status = load_one_line(&maze->solved_matrix, f);
    } while (status == 0);
    if (fclose(f) == -1) {
        return -1;
    }
    return status;
}

static void destroy_maze_line(maze_line_t *line)
{
    lvector_destroy(*line);
}

int maze_create(struct maze *maze, const lstr_t *filename)
{
    if (lstr_dup(&maze->filename, filename) == -1) {
        return -1;
    }
    lvector_create(maze->matrix, 0, destroy_maze_line);
    lvector_create(maze->solved_matrix, 0, destroy_maze_line);
    if (load_maze_lines(maze) == -1) {
        return -1;
    }
    return 0;
}