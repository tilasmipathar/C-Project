#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"

#include "Globals.hpp"
#include "Functions.hpp"
#include "Logic.hpp"
#include "Game.hpp"
#include "Draw.hpp"
#include "PlayGame.hpp"


void Quit()
{
    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char* args[])
{
    PlayGame();
    return 0;
}