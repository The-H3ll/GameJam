/*
 *  Created by M.Labhairi
 */

/*
 * Structures 
 */


#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>


# define WIDTH	800
# define HEIGHT	640
# define BULLET_SPEED 16
# define ENEMY_SPEED 1

typedef struct {

	SDL_Renderer *render;
	SDL_Window *win;
	int up;
	int down;
	int left;
	int right;
	int fire;
} App;

 typedef struct node {

	float x;
	float y;
	float dx;
	float dy;
	int w;
	int h;
	int health;
	SDL_Texture *tex;
	struct node *next;
} Entity;

typedef struct {
	Entity fighterHead, *fighterTail;
} Stage;

/*
 * Prototypes
 */

App app;
Entity player;
Entity bullet;
Stage stage;

#endif
