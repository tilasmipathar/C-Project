/*FUNCTION TO RUN THE GAME*/
#include "header.hpp"

using namespace std;

Brickbreaker* brickbreaker = nullptr;

void rungame()
{
    brickbreaker = new Brickbreaker();

    //Controlling the FPS
    const int FPS = 30;
    const int framedel = 1000/FPS;

    Uint32 framestart;
    int frametime;

    char title[] = "Brickbreaker";
    brickbreaker->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 960, false);

    while(brickbreaker->running())
    {
        framestart = SDL_GetTicks();

        //game functions
        brickbreaker->eventhandling();
        brickbreaker->input();
        brickbreaker->update();
        brickbreaker->render();

        frametime = SDL_GetTicks() - framestart;

        if(framedel > frametime)
        {
            SDL_Delay(framedel-frametime);
        }
    }

    brickbreaker->clean();
}

