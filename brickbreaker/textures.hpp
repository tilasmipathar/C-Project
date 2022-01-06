#ifdef __gnu_linux__
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#endif

//Global vars for all the textures
SDL_Texture* bckgrd1;
SDL_Texture* brick1;
SDL_Texture* brick2;
SDL_Texture* brick3;
SDL_Texture* brick4;

//Bricks and array storing whether a brick has been broken or not
SDL_Rect destR[68];
bool brickcol[68];