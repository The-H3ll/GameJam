/*
 * Created by M.Labhairi
 */

#include "main.h"
#include "event.h"


int	main(void)
{
	memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));
	memset(&bullet, 0, sizeof(Entity));

	SDL_Window *win = NULL;
	SDL_Texture *img_ship = NULL;
	SDL_Texture *img_shot = NULL;
	SDL_Texture *img_enemy = NULL;
	SDL_Texture *img_background = NULL;
	SDL_Renderer *render = NULL;
	SDL_Rect ship_pos, shoot_pos, enemy_pos;
	static int enemySpawn;

	ship_pos.x = 100;
	ship_pos.y = 100;
	ship_pos.w = 50;
	ship_pos.h = 50;

	enemy_pos.x = (WIDTH - 100);
	enemy_pos.y = 100;
	enemy_pos.w = 30;
	enemy_pos.h = 30;

	win = SDL_CreateWindow("M.L", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	img_ship = IMG_LoadTexture(render, "Ship3.png");
	img_shot = IMG_LoadTexture(render, "shot1_asset.png");
	img_enemy = IMG_LoadTexture(render, "enemy.png");
	img_background = IMG_LoadTexture(render, "Nebula Blue.png");
	if (img_shot == NULL || img_shot == NULL || img_background == NULL || img_enemy == NULL)
	{
		printf("Texture Doesnt load\n");
		exit(3);
	}
	SDL_RenderClear(render);
	while (1)	
	{
		player_event();
		if (app.up && ship_pos.y > 0)
			ship_pos.y -= 2;
		if (app.down && ship_pos.y <= (HEIGHT - ship_pos.h))
			ship_pos.y += 2;
		if (app.left && ship_pos.x > 0)
			ship_pos.x -= 2;
		if (app.right && ship_pos.x < (WIDTH - ship_pos.w))
			ship_pos.x += 2;
		if (app.fire && bullet.health == 0)
		{
				shoot_pos.x = ship_pos.x;
				shoot_pos.y = ship_pos.y;
				shoot_pos.w = 50;
				shoot_pos.h = 50;
				bullet.health = 1;			
		}
		shoot_pos.x += BULLET_SPEED;
		shoot_pos.y += 0;
		if (shoot_pos.x > WIDTH)
				bullet.health = 0;
		SDL_RenderCopy(render, img_background, NULL, NULL);
		SDL_RenderCopy(render, img_ship, NULL, &ship_pos);
		enemy_pos.x -= ENEMY_SPEED;
		if (enemy_pos.x <= 0)
		{
			enemy_pos.x = WIDTH - 100;
			enemy_pos.y = rand() % HEIGHT / 2;
		}
		SDL_RenderCopy(render, img_enemy, NULL, &enemy_pos);
		if (bullet.health > 0)
			SDL_RenderCopy(render, img_shot, NULL, &shoot_pos);
		SDL_RenderPresent(render);
	}
	SDL_DestroyRenderer(render);
	SDL_DestroyTexture(img_background);
	SDL_DestroyTexture(img_ship);
	SDL_DestroyTexture(img_shot);
	SDL_DestroyTexture(img_enemy);
	SDL_DestroyWindow(win);
	return (0);
}
