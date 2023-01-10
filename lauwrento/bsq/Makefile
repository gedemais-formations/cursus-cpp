NAME=bsq

CC=gcc
FLAGS=-Wall
FLAGS+=-Werror
FLAGS+=-Wextra

DEBUG?=0
ifeq ($(DEBUG), 1)
  FLAGS+=-g3 -fsanitize=address
endif

VALGRIND_CHECK?=0
ifeq ($(VALGRIND_CHECK), 1)
  FLAGS+=-g
endif

OPTI?=0
ifeq ($(OPTI), 1)
  FLAGS+=-Ofast -ffast-math -march=native
endif

SRC_PATH=src/
SRC_NAME=bsq.c\
  error.c\
  ft_split.c\
  ft_strdup.c\
  ft_strchr.c\
  get_map.c\
  str_len.c\
  solver.c\
  read_fd.c\
  math.c\
  free.c\
  print.c\
  get_metadata.c\
  get_board.c


SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))

INC_PATH=src/include/
INC_NAME=error.h\
  main.h

INC=$(addprefix $(INC_PATH), $(INC_NAME))

OBJ_PATH=obj/
OBJ_NAME=$(addprefix $(OBJ_PATH), $(SRC_NAME))
OBJS=$(OBJ_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@printf "Compiling $@"
	@printf "                     \\n\r"
	@$(CC) $(FLAGS) -I$(INC_PATH) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all