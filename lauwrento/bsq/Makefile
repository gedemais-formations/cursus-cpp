CC=gcc
FLAGS=-Wall\
  -Werror\
  -Wextra\
  -g3
 # -fsanitize=address

SRC_PATH=src/
SRC_NAME=bsq.c\
		 error.c\
		 parser.c


SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))

INC_PATH=src/include/
INC_NAME=error.h\
		 main.h

INC=$(addprefix $(INC_PATH), $(INC_NAME))

BIN_PATH=bin/
OBJ_PATH=$(addprefix $(BIN_PATH), $(SRC_NAME))
OBJS=$(OBJ_PATH:.c=.o)

all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o bsq
	
$(BIN_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@printf "Compiling $@"
	@printf "									   \\r"
	@$(CC) $(FLAGS) -I$(INC_PATH) -o $@ -c $<

clean:
	rm -rf bin/*.o
