COMPIL = gcc
FLAGSCOMPIL = -W -Wall -g3
FLAGSLINK = -lSDL2

all: src/main.o src/error.o src/screen_handling.o src/util.o src/jdlv.o
	gcc -o jdlv src/error.o src/main.o src/screen_handling.o src/util.o src/jdlv.o $(FLAGSLINK)

%.o: %.c
	$(COMPIL) -c $< -o $@ $(FLAGSCOMPIL)

clean:
	rm -f *.o
