#pragma once

#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include "Game.h"
using namespace std;

class TextManager{
    public:

    static SDL_Texture* Loadtexture(const char* filename); 
    static void Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest);
};