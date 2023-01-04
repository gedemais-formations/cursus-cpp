NAME=bsq

CC=gcc
FLAGS=-Wall
FLAGS+=-Werror
FLAGS+=-Wextra

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	FLAGS += -g3 -fsanitize=address
endif

SRC_PATH=src/
SRC_NAME=bsq.c\
  error.c\
  parser.c\
  ft_split.c\
  ft_strdup.c\
	ft_strchr.c


SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))

INC_PATH=src/include/
INC_NAME=error.h\
  main.h

INC=$(addprefix $(INC_PATH), $(INC_NAME))

BIN_PATH=bin/
OBJ_PATH=$(addprefix $(BIN_PATH), $(SRC_NAME))
OBJS=$(OBJ_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	
$(BIN_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@printf "Compiling $@"
	@printf "									   \\r"
	@$(CC) $(FLAGS) -I$(INC_PATH) -o $@ -c $<

clean:
	rm -rf bin/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all