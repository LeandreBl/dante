NAME = solver

CFLAGS +=

CC	?= gcc

STATIC_LIB_FOLDERS = arguments-handler lvector c-string

LDLIBS	+= -llargs -llstr

LDFLAGS += $(addprefix -L ./, $(STATIC_LIB_FOLDERS))

SRC =	src/main.c \
		src/common/logs.c \
		src/common/vector2.c \
		src/common/dante_arguments.c \
		src/common/maze/maze_create.c \
		src/common/maze/maze_destroy.c \
		src/common/maze/maze_get_possible_next_moves.c \
		src/common/maze/maze_is_celltype.c \
		src/common/maze/maze_is_empty.c \
		src/common/maze/maze_is_out_of_bound.c \
		src/common/maze/maze_set_celltype.c \
		src/common/maze/maze_fill_solved_matrix.c \
		src/solver/solver_create.c \
		src/solver/solver_destroy.c \
		src/solver/solver_run.c \
		src/solver/solver_move.c \
		src/solver/solver_backtrack.c \
		src/solver/solver_display.c \
		

OBJ = $(SRC:.c=.o)

CPPFLAGS += -iquote ./include
CPPFLAGS += $(addprefix -iquote ./, $(addsuffix /include, $(STATIC_LIB_FOLDERS)))

CFLAGS += -Wextra -Wall

GREEN		= '\033[0;32m'
NO_COLOR	= '\033[0m'

%.o : %.c
	@$ $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo "$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"
.SUFFIXES: .o .c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

dependencies:
	for folder in $(STATIC_LIB_FOLDERS) ; do \
		$(MAKE) -C $$folder static ; \
	done

debug: CFLAGS += -g3
debug: all

opti: CFLAGS += -O3
opti: re

clean:
	$(RM) $(OBJ)
	for folder in $(STATIC_LIB_FOLDERS) ; do \
		$(MAKE) -C $$folder clean ; \
	done

fclean: clean
	$(RM) $(NAME)
	for folder in $(STATIC_LIB_FOLDERS) ; do \
		$(MAKE) -C $$folder fclean ; \
	done

re: fclean dependencies all

.PHONY: all clean fclean re dependencies