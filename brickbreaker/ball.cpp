#include "ball.hpp"

using namespace std;

//Constructor
ball::ball(int height, int width, int xcor, int ycor, int vxinit, int vyinit)
{
    ball_pos = new pos();
    balltext = new texture();
    balltext->ballrect = new SDL_Rect();
    ball_pos->pos = new vect();
    ball_pos->vel = new vect();
    ball_pos->pos->x = xcor;
    ball_pos->pos->y = ycor;
    ball_pos->vel->x = vxinit;
    ball_pos->vel->y = vyinit;

    balltext->width = width;
    balltext->height = height;
}

//Returns coordinates of ball
pos* ball::getpos()
{
    return ball_pos;
};

//Returns texture properties of ball
texture* ball::gettexture()
{
    return balltext;
}

//Updates velocity w.r.t paddle and walls of window
void ball::updatevel(SDL_Rect* paddle)
{
    
    if(ball_pos->pos->x>=paddle->x+8 && ball_pos->pos->x+24<=paddle->x+paddle->w)
    {
        if(ball_pos->pos->y+16>=paddle->y && ball_pos->pos->y<=paddle->y+paddle->h)
        {
            (ball_pos->vel->y)*=-1;
        } 
    }
    if((ball_pos->vel->y<0 && ball_pos->pos->y<=0) or (ball_pos->vel->y>0 && ball_pos->pos->y>=944))
    {
        (ball_pos->vel->y)*=-1;
    }
    if((ball_pos->vel->x<0 && ball_pos->pos->x<=0) or (ball_pos->vel->x>0 && ball_pos->pos->x>=1264))
    {
        (ball_pos->vel->x)*=-1;
    }
}

//Updating coordinates of the ball
void ball::updatecord()
{
    ball_pos->pos->x+=ball_pos->vel->x;
    ball_pos->pos->y+=ball_pos->vel->y;
}

//Rendering the ball
void ballrender(SDL_Renderer* gamerenderer, texture* balltext, pos* ballpos)
{
    balltext->ballrect->h = balltext->height;
    balltext->ballrect->w = balltext->width;
    balltext->ballrect->x = ballpos->pos->x;
    balltext->ballrect->y = ballpos->pos->y;
    SDL_SetRenderDrawColor(gamerenderer, 255,255,255,255);
    SDL_RenderDrawRect(gamerenderer, balltext->ballrect);
    SDL_RenderFillRect(gamerenderer, balltext->ballrect);
    SDL_SetRenderDrawColor(gamerenderer, 255,255,255,255);
};