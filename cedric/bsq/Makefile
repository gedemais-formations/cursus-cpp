NAME=bsq

CC=gcc
FLAGS=-Wall -Werror -Wextra

DEBUG?=0
ifeq ($(DEBUG),1)
	FLAGS+=-g3 -fsanitize=address
endif

VALGRIND_CHECK?=0
ifeq ($(VALGRIND_CHECK),1)
	FLAGS+= -g
endif

OPTI?=0
ifeq ($(OPTI),1)
	FLAGS+=-Ofast -ffast-math -march=native
endif

SRC_PATH=src/

SRC_NAME=main.c\
		bsq.c\
		get_map.c\
		solve.c\
		free.c\
		strdup.c

SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ=$(SRC:.c=.o)

INC_PATH=include/
INC_NAME=bsq.h
INC=$(addprefix $(INC_PATH), $(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -I$(INC_PATH) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

$(info $(SRC))
$(info $(INC))
$(info $(OBJ))