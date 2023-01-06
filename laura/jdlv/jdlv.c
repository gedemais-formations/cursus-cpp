#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SQUARE_SIZE 8 //Carré de 8px*8px
#define BOARD_WIDTH 20 //Nombre de cellules (largeur)
#define BOARD_HEIGHT 30 //Nombre de cellules (hauteur)
#define PROBA 65
#define PROBA_GREEN 95

#define EMPTY 0
#define BLUE 1
#define RED 2
#define GREEN 3

char ** tab;
SDL_Renderer * renderer;
SDL_Window * window = NULL;

//Evite de déborder du board
int max(int m, int n) {
	if (n > m) m = n;
	return m;
}

//Evite de déborder du board
int min(int m, int n) {
	if (n < m) m = n;
	return m;
}

char neighbours(char ** tab, int x, int y) {
	int i, j;
	char n = 0;
	for(i = max(x - SQUARE_SIZE, 0); i < min(x + SQUARE_SIZE*2, BOARD_WIDTH*SQUARE_SIZE); i+=SQUARE_SIZE) {
		for(j = max(y - SQUARE_SIZE, 0); j < min(y + SQUARE_SIZE*2, BOARD_HEIGHT*SQUARE_SIZE); j+=SQUARE_SIZE) {
			if(!(x == j && y == j) && tab[i][j] == BLUE) n++;
		}
	}
	return n;
}

void newGeneration() {
	int x, y, random;
	char n;
	for(x = 0; x < BOARD_WIDTH*SQUARE_SIZE; x+=SQUARE_SIZE) {
		for(y = 0; y < BOARD_HEIGHT*SQUARE_SIZE; y+=SQUARE_SIZE) {
			n = neighbours(tab, x, y);
			if(tab[x][y] != EMPTY) {
				if(tab[x][y] == RED && n != 3) {
					tab[x][y] = EMPTY;
					SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderFillRect(renderer, &rect);
				}
				else if(n == 3 || tab[x][y] == GREEN) {
					tab[x][y] = BLUE;
					SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
					SDL_RenderFillRect(renderer, &rect);
				}
				else if(n < 2 || n > 3) {
					tab[x][y] = RED;
					SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
					SDL_RenderFillRect(renderer, &rect);
				}
			}
			//Génère aléatoirement des cellules vertes aux places vides
			else {
				random = (int)(1 + ((double)rand() /  RAND_MAX * (100 - 1 + 1)));
				if(random > PROBA_GREEN) {
					tab[x][y] = GREEN;
					SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
					SDL_RenderFillRect(renderer, &rect);
				}
			}
		}
	}
}

void drawBlueSquare(SDL_Renderer * renderer, int x, int y) {
	SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void * newThread(void * threadid) {
	long tid;
	tid = (long)threadid;
	printf("Hello World! It's me, thread #%ld!\n", tid);
	while(1) {
		sleep(1);
		newGeneration();
		SDL_RenderPresent(renderer);
		SDL_UpdateWindowSurface(window);
	}
	pthread_exit(NULL);
}

int main() {
	SDL_Surface * screen_surface = NULL;
	SDL_Event e;
	pthread_t threads[1];
	int x, y, random;
	char quit = 0;
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		puts("Failed to initialise SDL");
		return - 1;
	}
	window = SDL_CreateWindow( "Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(!window) {
		puts("Failed to create window");
		return -1;
	}
	screen_surface = SDL_GetWindowSurface(window);
	if(!screen_surface) {
		puts("Failed to get window surface");
		return -1;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!renderer) {
		puts("Failed to render");
		return -1;
	}
	//Initialise l'aléatoire
	srand(time(NULL));
	//Première génération : on répartit aléatoirement des cellules vivantes (bleues) dans l'espace de jeu
	tab = (char **)malloc(BOARD_WIDTH*SQUARE_SIZE*(sizeof(char *)));
	for(x = 0; x < BOARD_WIDTH*SQUARE_SIZE; x+=SQUARE_SIZE) {
		tab[x] = (char *)malloc(BOARD_HEIGHT*SQUARE_SIZE);
		for(y = 0; y < BOARD_HEIGHT*SQUARE_SIZE; y+=SQUARE_SIZE) {
			random = (int)(1 + ((double)rand() /  RAND_MAX * (100 - 1 + 1)));
			if(random > PROBA) {
				drawBlueSquare(renderer, x, y);
				tab[x][y] = BLUE;
			}
			else tab[x][y] = 0;
		}
	}
	SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(window);
    	pthread_create(&threads[1], NULL, newThread, (void *)1);
	while(!quit){ 
    		while(SDL_PollEvent(&e)){ 
    			if(e.type == SDL_QUIT) quit = 1;
    		} 
    	}
    	free(tab);
    	//for(x = 0; x < BOARD_WIDTH*SQUARE_SIZE; x+=SQUARE_SIZE) free(tab[x]);
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_Quit();
	return 0;
}
