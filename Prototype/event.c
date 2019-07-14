/*
    * Created by M.Labhairi (2019)
 */

#include "main.h"
#include "event.h"



void    player_event(void)
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            wrak(&e.key);
            break ;
        case SDL_KEYUP:
            up(&e.key);
            break;
        }
    }
}

void    wrak(SDL_KeyboardEvent *e)
{
    if (e->repeat == 0)
    {
        if (e->keysym.scancode == SDL_SCANCODE_UP)
        {
            app.up = 1;           
        }
        if (e->keysym.scancode == SDL_SCANCODE_DOWN)
        {
            app.down = 1;
        }
        if (e->keysym.scancode == SDL_SCANCODE_LEFT)
        {
            app.left = 1;
        }
        if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
        {
            app.right = 1;
        }
        if (e->keysym.scancode == SDL_SCANCODE_SPACE)
        {
            app.fire = 1;
        }
    }
}

void    up(SDL_KeyboardEvent *e)
{
    if (e->repeat == 0)
    {
        if (e->keysym.scancode == SDL_SCANCODE_UP)
        {
            app.up = 0;           
        }
        if (e->keysym.scancode == SDL_SCANCODE_DOWN)
        {
            app.down = 0;
        }
        if (e->keysym.scancode == SDL_SCANCODE_LEFT)
        {
            app.left = 0;
        }
        if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
        {
            app.right = 0;
        }
        if (e->keysym.scancode == SDL_SCANCODE_SPACE)
        {
            app.fire = 0;
        }
    }
}