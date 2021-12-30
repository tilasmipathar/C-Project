#include "TextManager.hpp"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

SDL_Texture* TextManager::Loadtexture(const char* filename){
    SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* player = SDL_CreateTextureFromSurface(Game::renderer,surface);
	SDL_FreeSurface(surface);

    return player;
}

void TextManager::Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest){
    SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}