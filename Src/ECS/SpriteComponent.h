#pragma once

#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component
{
private:
    PositionComponent* position;
    SDL_Texture *texture;
    SDL_Rect srcRect,destRect;

public:
    SpriteComponent(/* args */) = default;
    SpriteComponent(const char* path){
        setTex(path);
    }

    void setTex(const char* path){
        texture = TextManager::Loadtexture(path);
    }

    void init() override{
        position = &entity->getComponent<PositionComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 1000;
        destRect.w = destRect.h = 128;

    }

    void update() override{
        destRect.x = position->x();
        destRect.y = position->y();

    }

    void draw() override{
        TextManager::Draw(texture, srcRect, destRect);
    }
};

