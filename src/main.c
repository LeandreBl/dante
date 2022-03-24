#include <arguments.h>

#include "solver.h"
#include "dante_arguments.h"
#include "logs.h"

static int argument_parse_filename(struct solver_arguments *args, const char **argv)
{
    return lstr_set(&args->filename, argv[1], strlen(argv[1]));
}

static const arg_handler(struct solver_arguments) ARGUMENTS_OPTS[] = {
    {
        .opt = "-f",
        .optlong = "--file",
        .help = "Filepath of the maze",
        .argument_needed = true,
        .args_type_info = "FILEPATH",
        .handler = &argument_parse_filename,
    },
    {
        .opt = "-h",
        .optlong = "--help",
        .help = "Display this help",
        .argument_needed = false,
        .args_type_info = NULL,
        .handler = OPTS_HELP_HANDLER,
    }
};

int main(int ac, const char *av[])
{
    struct solver_arguments args;
    struct dante_solver solver;
    opts_handler_t opts;

    opts_create(&opts, av[0], ARGUMENTS_OPTS, sizeof(ARGUMENTS_OPTS) / sizeof(*ARGUMENTS_OPTS));
    if (solver_arguments_create(&args) == -1) {
        logs_error("Error: cannot create arguments handlers: %m\n");
        return 1;
    }
    if (opts_get(&opts, ac, av, &args) == -1) {
        return 1;
    }
    if (args.filename.len == 0) {
        logs_error("Error: missing -f or --file option\n");
        return 1;
    }
    if (solver_create(&solver, &args.filename) == -1) {
        logs_error("Error: cannot create solver object: \"%s\" %m\n", args.filename.i);
        return 1;
    }
    solver_arguments_destroy(&args);
    solver_run(&solver);
    solver_display(&solver);
    solver_destroy(&solver);
    return 0;
}