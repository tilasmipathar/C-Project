/*Header File*/
#ifdef __gnu_linux__
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#endif

#include "ball.hpp"
#include "Brickbreaker.hpp"
#include <bits/stdc++.h>

void textinit(SDL_Renderer* gamerenderer);
void bricks();
void rungame();
void textrender(SDL_Renderer* gamerenderer);
void ballrender(SDL_Renderer* gamerenderer, texture* balltext, pos* ballpos);
int checkcollisions(ball* gameball, int score);
void bckgrdload(SDL_Renderer* gamerenderer);
