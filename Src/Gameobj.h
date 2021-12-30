#pragma once
#include "Game.h"

class Gameobj
{
private:
    SDL_Rect srcR,destR;
    SDL_Texture* objTexture;


    int xpos,ypos;
public:
    Gameobj(const char* texturesheet,int x,int y);
    ~Gameobj();

    void Update();
    void Render();
};
