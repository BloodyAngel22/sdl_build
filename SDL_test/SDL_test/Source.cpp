#include <SDL.h>
#include <stdio.h>

int win_width = 1280, win_height = 720;
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

void init(); void de_init(int error);

void init() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Couldn't init sdl, Error %s", SDL_GetError());
		system("pause");
		de_init(1);
	}

	win = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		win_width, win_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == NULL) {
		printf("window couldn't init %s", SDL_GetError());
		system("pause");
		SDL_Quit();
		de_init(1);
	}

	ren = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	if (ren == NULL) {
		printf("renderer couldn't init %s", SDL_GetError());
		system("pause");
		SDL_Quit();
		de_init(1);
	}
}

void de_init(int error) {
	if (ren != NULL) SDL_DestroyRenderer(ren);
	if (win != NULL) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}

int main(int argc, char* argv[]) {

	init();

	SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
	SDL_RenderClear(ren);
	

	//Флаг
	/*SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	for (int i = 0; i < 100; i++) {
		SDL_RenderDrawLine(ren, 400, win_height / 2 - 100 - i, win_width - 400, win_height / 2 - 100 - i);
		SDL_RenderPresent(ren);
	}
	SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
	for (int i = 0; i < 100; i++) {
		SDL_RenderDrawLine(ren, 400, win_height / 2 - i, win_width - 400, win_height / 2 - i);
		SDL_RenderPresent(ren);
	}
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	for (int i = 0; i < 100; i++) {
		SDL_RenderDrawLine(ren, 400, win_height / 2 + 100 - i, win_width - 400, win_height / 2 + 100 - i);
		SDL_RenderPresent(ren);
	}*/

	//ось 
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	for (int i = 0; i < 5; i++) {
		SDL_RenderDrawLine(ren, 0, win_height / 2 + 5 - i, win_width, win_height / 2 + 5 - i);
		SDL_RenderDrawLine(ren, win_width / 2 - 5 + i, 0, win_width / 2 - 5 + i, win_height);
	}

	//парабола
	for (float x = 0; x < 50; x = x + 0.005) {
		float y = x * x;
		SDL_RenderDrawPoint(ren, win_width / 2 + x + 1, win_height / 2 - y + 2);
		SDL_RenderDrawPoint(ren, win_width / 2 - x - 5, win_height / 2 - y + 2);
		SDL_RenderPresent(ren);
	}


	SDL_RenderPresent(ren);

	SDL_Delay(3000);

	de_init(0);
	return 0;
}