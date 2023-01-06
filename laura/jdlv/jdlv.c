#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <time.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SQUARE_SIZE 8 //Carré de 8px*8px
#define BOARD_WIDTH 20 //Nombre de cellules (largeur) ; valeur à remplacer
#define BOARD_HEIGHT 30 //Nombre de cellules (hauteur) ; valeur à remplacer
#define PROBA 60

void drawSquare(SDL_Renderer * renderer, int x, int y) {
	SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

int main(int argc, char ** argv) {
	SDL_Window * window = NULL;
	SDL_Surface * screen_surface = NULL;
	SDL_Event e;
	SDL_Renderer * renderer;
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
	for(x = 0; x < BOARD_WIDTH*SQUARE_SIZE; x+=SQUARE_SIZE) {
		for(y = 0; y < BOARD_HEIGHT*SQUARE_SIZE; y+=SQUARE_SIZE) {
			random = (int)(1 + ((double)rand() /  RAND_MAX * (100 - 1 + 1)));
			if(random > PROBA) drawSquare(renderer, x, y);
		}
	}
	SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(window);
	while(!quit){ 
    		while(SDL_PollEvent(&e)){ 
    			if(e.type == SDL_QUIT) quit = 1; 
    		} 
    	}
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_Quit();
	return 0;
}
