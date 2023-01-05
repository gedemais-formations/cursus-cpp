COMPIL = gcc
FLAGSCOMPIL = -W -Wall
FLAGSLINK = -lSDL2

all: src/main.o src/error.o src/screen_handling.o
	gcc -o jdlv src/error.o src/main.o src/screen_handling.o $(FLAGSLINK)

%.o: %.c
	$(COMPIL) -c $< -o $@ $(FLAGSCOMPIL)

clean:
	rm -f *.o
