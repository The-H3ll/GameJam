#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "main.h"

#define TRUE 	1
#define FALSE	0
#define width	800
#define height	640


//void	pause();
//void	init();

int	main(int argc, char **argv)
{
	init();
	pause();
	
	return EXIT_SUCCESS;
}

/*
 * IT will make init the window
 */

void	init(void)
{
	SDL_Window 	*win;
	SDL_Renderer 	*render;
	SDL_Texture	*fond;
	SDL_Surface  	*img_fond;
	SDL_Rect	font_pos;
	SDL_Rect	zozo_pos;


	win = SDL_CreateWindow("M.L", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0); // Creation of the window
	render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED); // Creation of the rendring
	img_fond = SDL_LoadBMP("lac_en_montagne.bmp"); // loading the image
//	img_zozo = IMG_Load("sapin.png"); // loading the second img
//	SDL_SetColorKey(img_zozo, SDL_TRUE, SDL_MapRGB(img_zozo->format, 0, 0, 255));
	fond = SDL_CreateTextureFromSurface(render, img_fond); // Creation of the texture from surface
	//texture = SDL_CreateTextureFromSurface(render, img_zozo); // Creation of the texture from surface
	SDL_FreeSurface(img_fond); // free the surface we dont need to use it anymore
	//SDL_FreeSurface(img_zozo);
	SDL_RenderCopy(render, fond, NULL, NULL);
	//SDL_RenderCopy(render, texture, NULL, &zozo_pos);
	SDL_RenderPresent(render);
}

/*
 * it takes all the event and make it one
 */

/*
 * To Pause the WINDOW when its initialise
 */

void	pause(void)
{
	int continuer;
	SDL_Event event;

	continuer = TRUE;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				continuer = FALSE;
				break;
			case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					continuer = FALSE;
					break;
			}
		}
		
	}
}
