#pragma once
#include "Game.h"

class Map{
    private:
        SDL_Rect src,dest;
        SDL_Rect srcM,destM;
        SDL_Texture* bumper_30;
        SDL_Texture* bumper_20;
        SDL_Texture* bumper_10;
        SDL_Texture* trans;
        SDL_Texture* board;
        SDL_Texture* side,*hbump,*mulx2,*mulx3,*mulx5;

        int map[25][30];

    public:

        Map();
        ~Map(); 
        
        void LoadMap(int arr[35][30]);
        void DrawMap();
};