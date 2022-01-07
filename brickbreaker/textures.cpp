/*Textures File*/
#include "textures.hpp"
#include "ball.hpp"
#include<iostream>

using namespace std;


//Initialising all the bricks and background
void textinit(SDL_Renderer* gamerenderer)
{
    SDL_Surface* tempsurf = IMG_Load("brickbreaker/assets/bckgrd.jpg");
    bckgrd1 = SDL_CreateTextureFromSurface(gamerenderer, tempsurf);
    tempsurf = IMG_Load("brickbreaker/assets/brick1.png");
    brick1 = SDL_CreateTextureFromSurface(gamerenderer, tempsurf);
    tempsurf = IMG_Load("brickbreaker/assets/brick2.png");
    brick2 = SDL_CreateTextureFromSurface(gamerenderer, tempsurf);
    tempsurf = IMG_Load("brickbreaker/assets/brick3.png");
    brick3 = SDL_CreateTextureFromSurface(gamerenderer, tempsurf);
    tempsurf = IMG_Load("brickbreaker/assets/brick4.png");
    brick4 = SDL_CreateTextureFromSurface(gamerenderer, tempsurf);
    if(!bckgrd1 or !brick1 or !brick2 or !brick3 or !brick4)
    {
        cout << "Error Loading textures" << endl;
    }
    cout << bckgrd1 << " " << brick1 << " " << brick2 << " " << brick3 << " " << brick4 << endl;
    SDL_FreeSurface(tempsurf);
    for(int i=0; i<68; i++)
    {
        brickcol[i] = false;
    }
}

//Setting the size and location of all the bricks
void bricks()
{
    for(int i=0; i<19; i++)
    {
        destR[i].h = 64;
        destR[i].w = 64;
        destR[i].x = 32+64*i;
        destR[i].y = 32;
    }

    for(int i=19; i<28; i++)
    {
        destR[i].h = 64;
        destR[i].w = 128;
        destR[i].x = 64+128*(i-19);
        destR[i].y = 128;
    }

    for(int i=28; i<45; i++)
    {
        destR[i].h = 64;
        destR[i].w = 64;
        destR[i].x = 96+64*(i-28);
        destR[i].y = 32+2*96;
    }

    for(int i=45; i<53; i++)
    {
        destR[i].h = 64;
        destR[i].w = 128;
        destR[i].x = 128+128*(i-45);
        destR[i].y = 32+3*96;
    }

    for(int i=53; i<68; i++)
    {
        destR[i].h = 64;
        destR[i].w = 64;
        destR[i].x = 160+64*(i-53);
        destR[i].y = 32+4*96;
    }
}

//Loading the background
void bckgrdload(SDL_Renderer* gamerenderer)
{
    SDL_RenderCopy(gamerenderer, bckgrd1, NULL, NULL);
}

//Rendering the bricks if they have not been hit and broken
void textrender(SDL_Renderer* gamerenderer)
{
    for(int i=0; i<19; i++)
    {
        if(brickcol[i]==false)
        {
            if(i%2==0)
            {
                SDL_RenderCopy(gamerenderer, brick1, NULL, &destR[i]);
            }
            else
            {
                SDL_RenderCopy(gamerenderer, brick2, NULL, &destR[i]);
            }
        }
    }

    for(int i=19; i<28; i++)
    {
        if(brickcol[i]==false) SDL_RenderCopy(gamerenderer, brick4, NULL, &destR[i]);
    }

    for(int i=28; i<45; i++)
    {
        if(brickcol[i]==false)
        {
            if(i%2==0)
            {
                SDL_RenderCopy(gamerenderer, brick1, NULL, &destR[i]);
            }
            else
            {
                SDL_RenderCopy(gamerenderer, brick3, NULL, &destR[i]);
            }
        }
    }

    for(int i=45; i<53; i++)
    {
        if(brickcol[i]==false) SDL_RenderCopy(gamerenderer, brick4, NULL, &destR[i]);
    }

    for(int i=53; i<68; i++)
    {
        if(brickcol[i]==false)
        {
            if(i%2==0)
            {
                SDL_RenderCopy(gamerenderer, brick1, NULL, &destR[i]);
            }
            else
            {
                SDL_RenderCopy(gamerenderer, brick2, NULL, &destR[i]);
            }
        }
    }
}

//Checking for collisions of the ball with the bricks, and returning the updated score
int checkcollisions(ball* gameball, int score)
{
    int a = score;
    bool dflag = false;
    for(int i=0; i<68; i++)
    {
        if(SDL_HasIntersection(gameball->gettexture()->ballrect, &destR[i]) && brickcol[i]==false)
        {
            brickcol[i] = true;
            
            int ballx = gameball->gettexture()->ballrect->x;
            int brickx = destR[i].x;
            int bally = gameball->gettexture()->ballrect->y;
            int bricky = destR[i].y;
            int brickh = destR[i].h;
            int brickw = destR[i].w;

            
            if(ballx<=brickx or (ballx+16)>=(brickx+brickw))
            {
                if(!dflag) gameball->getpos()->vel->x*=-1;
            }
            else if(bally<=bricky or (bally+16)>=(bricky+brickh))
            {
                if(!dflag) gameball->getpos()->vel->y*=-1;
            }
            if(dflag)
            {
                gameball->getpos()->vel->y*=-1;
                gameball->getpos()->vel->x*=-1;
            }
            dflag = true;

            a+=1;
        }
    }
    return a;
};