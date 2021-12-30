#include "Gameobj.h"
#include "TextManager.hpp"

Gameobj::Gameobj(const char* texturesheet, int x,int y)
{

    objTexture = TextManager::Loadtexture(texturesheet);
    xpos = x;
    ypos = y;
}

void Gameobj::Update(){
    xpos++;
    ypos++;

    srcR.h = 956;
    srcR.w = 535;
    srcR.x = 0;
    srcR.y = 0;

    destR.x = xpos;
    destR.y = ypos;
    destR.w = srcR.w /5;
    destR.h = srcR.h /5;

}

void Gameobj::Render(){
    SDL_RenderCopy(Game::renderer,objTexture,&srcR,&destR);
}
Gameobj::~Gameobj()
{
}
