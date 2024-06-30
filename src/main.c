#include <SDL2/SDL.h>
#include <stdio.h>
#include "maze.h"

int main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)

	{
		printf("SDL_Init Error: %s\n", SDL_GetError());

		return (1);
	}

	SDL_Window *win = SDL_CreateWindow("Maze Game", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)

	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/*  Define the map */

	int map[MAP_WIDTH][MAP_HEIGHT] =

	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	/* Define the playe */

	Player player = {3.5 * TILE_SIZE, 3.5 * TILE_SIZE, -1, 0, 0, 0.66};

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);

	renderMaze(ren, map, &player);

	SDL_RenderPresent(ren);
	SDL_Delay(5000);

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
