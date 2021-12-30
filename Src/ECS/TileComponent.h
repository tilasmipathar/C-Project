#pragma once

#include "ecs.h"
#include "PositionComponent.h"
#include "SDL2/SDL.h"
#include "SpriteComponent.h"

class TileComponent : public Component
{
private:
    /* data */
public:

    PositionComponent* position;
    SpriteComponent* sprite;
    TileComponent(/* args */)= default;

    SDL_Rect tileRect;
    int tileID;
    char* path;
    
    
    TileComponent(int x,int y,int w,int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.h = h;
        tileRect.w = w;
        tileID     = id;

        switch (tileID)
        {
        case 0:
            path = "../assets/water.png";
            break;
        
        case 1:
            path = "../assets/dirt.png";
            break;

        case 2:
            path = "../assets/grass.png";
            break;

        default:
            break;
        }
    }

    void init() override{
        entity->addComponent<PositionComponent>(tileRect.x,tileRect.y,tileRect.w,tileRect.h,1);
        position = &entity->getComponent<PositionComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
        
    }
};

