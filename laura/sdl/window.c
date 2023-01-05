#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

void put_pixel(unsigned char * buffer, int x, int y, int color) {
	int len;
	len = sizeof(int);
   	memcpy(&buffer[(y*SCREEN_WIDTH+x) * len], &color, len);
}

int main() {
	SDL_Window * window = NULL;
	SDL_Surface * screen_surface = NULL;
	SDL_Event e;
	SDL_Renderer * renderer;
	int width, height;
	unsigned char * buffer;
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
	SDL_UpdateWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!renderer) {
		puts("Failed to render");
		return -1;
	}
	width = SDL_GetWindowSurface(window)->w;
	height = SDL_GetWindowSurface(window)->h;
	buffer = (unsigned char *)SDL_GetWindowSurface(window)->pixels;
	SDL_LockSurface(screen_surface);
	for(int x = 0; x < width; x++) 
		for(int y = 0; y < height; y++) 
			put_pixel(buffer, x, y, 0x0000FF00);
	SDL_UnlockSurface(screen_surface);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(window);
	//Force la fenêtre à rester affichée tant qu'on ne quitte pas
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
