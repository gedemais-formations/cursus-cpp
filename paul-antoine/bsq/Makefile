NAME=bsq

CC=gcc

FLAGS=-Wall -Werror -Wextra


OPTI ?= 0
ifeq ($(OPTI), 1)
	FLAGS += -Ofast -ffast-math -march=native
endif

VALGRIND_CHECK ?= 0
ifeq ($(VALGRIND_CHECK), 1)
	FLAGS += -g
endif

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	FLAGS+= -g3
endif

SRC_PATH=src/

SRC_NAME=bsq.c\
		 bsq_error.c\
		 bsq_parser.c\
		 bsq_solver.c

SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH=include/

OBJS=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(LIB_MAT_VEC) $(LODEPNG) $(LIB_GLAD) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(INC)
	$(CC) $(FLAGS) -I$(INC_PATH) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all