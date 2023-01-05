COMPIL = gcc
FLAGSCOMPIL = -W -Wall
FLAGSLINK = -lSDL2

all: src/main.o src/error.o
	gcc -o jdlv src/error.o src/main.o $(FLAGSLINK)

%.o: %.c
	$(COMPIL) -c $< -o $@ $(FLAGSCOMPIL)

clean:
	rm -f *.o
