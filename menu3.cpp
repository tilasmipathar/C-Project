#include "SDL2/include/SDL.h"
#include <iostream>
#include "SDL2/include/SDL_ttf.h"
#include "SDL2/include/SDL_image.h"
#include "brickbreaker/header.hpp"
#include "PingPongBall/1v1/Headers.hpp"
#include "PingPongBall/AI(Final)/Headers1.hpp"

int main(int argc, char ** argv)
{

    // variables
    int x0=82,y0=663,y1=159,y2=382,y3=511,w=297,h=72,xe=391,ye=46,r=30;
    int game_num = 0;
    bool quit = false;
    SDL_Event event;
    int x,y;     
    Uint32 buttons;
    SDL_Rect srcM,destM;
 
    // init SDL

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 450, 957, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
 
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 

    SDL_Surface *text=IMG_Load("background.jpeg"); //give image name.
    SDL_Texture *img=SDL_CreateTextureFromSurface(renderer, text);
    SDL_FreeSurface(text);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,img,NULL,NULL);
    SDL_RenderPresent(renderer);
    // Texture class makes a texture of the menu screen image.

     while (!quit)
    {
        //std::cout<<game_num<<std::endl;
        SDL_PollEvent(&event);
        SDL_PumpEvents();
        
        buttons=SDL_GetMouseState(&x, &y);
 
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        
        }
    
    
	if(game_num==0){
        
		if((buttons && SDL_BUTTON_LMASK)!=0){
            		if( ((x-xe)*(x-xe))+((y-ye)*(y-ye)) <= r*r ){
                		quit = true;
            		}
            		if( (x > x0) && (x<(x0 + w)) && (y > y2) && (y < (y2 + h))){
            			game_num = 1;
            		}
            		if( (x > x0) && (x<(x0 + w)) && (y > y3) && (y < (y3 + h))){
                		game_num = 2;
            		}
           		 else if((x > x0) && (x<(x0 + w)) && (y > y0) && (y < (y0 + h))){
				game_num = 3;
                   
            	    }
	                
 	    }
 	}
    
    //cout << game_num << endl;
	if(game_num==1){
	//game 1
	//std::cout <<"1"<< std::endl;
        rungame();
        game_num=0;
	}
	if(game_num==2){
	//game 2
        //cout << game_num << endl;
        PlayGame();
        game_num=0;
	}
	if(game_num==3){
	//game 3
        PlayGame1();
        game_num=0;
	}
        
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
 
    return 0;
}
