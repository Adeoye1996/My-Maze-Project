#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>

#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define TILE_SIZE 64

typedef struct {
	float x, y;  // Player's position
	float dirX, dirY;  // Player's direction vector
	float planeX, planeY;  // Camera plane
} Player;

void renderMaze(SDL_Renderer *ren, int map[MAP_WIDTH][MAP_HEIGHT], Player *player);

#endif // MAZE_H
