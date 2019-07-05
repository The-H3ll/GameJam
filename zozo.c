#include "main.h"


void	initia(void);
//void	pose(void);

int	main(int argc, char **argv)
{
	initia();
//	pose();
	return EXIT_SUCCESS;
}

void	initia(void)
{
	SDL_Window *win = NULL;
	SDL_Texture *tex = NULL;
	SDL_Renderer *render = NULL;
	SDL_Surface *img = NULL;
	SDL_Rect	pos;

	pos.x = WIDTH / 2;
	pos.y = HEIGHT / 2;
	pos.w = 150;
	pos.h = 150;


	win = SDL_CreateWindow("M.L", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); // Creation of the window
	render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
//	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	img = SDL_LoadBMP("zozor.bmp");
	if (!(img))
		printf("ERROR");
	SDL_SetColorKey(img, 1, SDL_MapRGB(img->format, 0,0,255));
	tex = SDL_CreateTextureFromSurface(render, img);
	SDL_FreeSurface(img);

	int continuer;

	continuer = TRUE;
	SDL_Event event;
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type){
			case SDL_QUIT:
				continuer = FALSE;
				break ;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						continuer = FALSE;
						break;
					case SDLK_DOWN:
						pos.y++;
						break;

					case SDLK_UP:
						pos.y--;
						break ;
					case SDLK_RIGHT:
						pos.x++;
						break;
					case SDLK_LEFT:
						pos.x--;
						break;
				}
		}

		SDL_RenderClear(render);
		SDL_RenderCopy(render, tex, NULL, &pos);
		SDL_RenderPresent(render);
	}

}
