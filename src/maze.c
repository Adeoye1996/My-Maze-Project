#include "maze.h"

void renderMaze(SDL_Renderer *ren, int map[MAP_WIDTH][MAP_HEIGHT], Player *player)

{
	for (int x = 0; x < WINDOW_WIDTH; x++)

	{
		float cameraX = 2 * x / (float)WINDOW_WIDTH - 1;
		float rayDirX = player->dirX + player->planeX * cameraX;
		float rayDirY = player->dirY + player->planeY * cameraX;

		int mapX = (int)(player->x / TILE_SIZE);
		int mapY = (int)(player->y / TILE_SIZE);

		float sideDistX;
		float sideDistY;

		float deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		float deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		float perpWallDist;

		int stepX, stepY;
		int hit = 0;
		int side;

		if (rayDirX < 0)

		{
			stepX = -1;
			sideDistX = (player->x / TILE_SIZE - mapX) * deltaDistX;
		} else

		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->x / TILE_SIZE) * deltaDistX;
		}
		if (rayDirY < 0)

		{
			stepY = -1;
			sideDistY = (player->y / TILE_SIZE - mapY) * deltaDistY;
		} else

		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->y / TILE_SIZE) * deltaDistY;
		}

		while (hit == 0)

		{
			if (sideDistX < sideDistY)

			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else

			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}

			if (map[mapX][mapY] > 0) hit = 1;

		}

		if (side == 0) perpWallDist = (mapX - player->x / TILE_SIZE + (1 - stepX) / 2) / rayDirX;

		else perpWallDist = (mapY - player->y / TILE_SIZE + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;

		if (drawStart < 0) drawStart = 0;

		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;

		if (drawEnd >= WINDOW_HEIGHT) drawEnd = WINDOW_HEIGHT - 1;

		SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

		if (side == 1) SDL_SetRenderDrawColor(ren, 127, 0, 0, 255);

		SDL_RenderDrawLine(ren, x, drawStart, x, drawEnd);
	}
}
