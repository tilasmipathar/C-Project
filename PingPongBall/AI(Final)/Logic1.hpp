#include "Ball.hpp"

void Logic1()
{
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(keyState[SDL_SCANCODE_UP])
    {
        MyPaddle.y -= 6;
    }

    if(keyState[SDL_SCANCODE_DOWN])
    {
        MyPaddle.y += 6;
    }

    //--------
    
    //------


    if(MyPaddle.y < 1)
    {
        MyPaddle.y = 1;
    }

    if(MyPaddle.y + MyPaddle.h > 599)
    {
        MyPaddle.y = 599 - MyPaddle.h;
    }

    if(OpponentPaddle.y < 1)
    {
        OpponentPaddle.y = 1;
    }

    if(OpponentPaddle.y + OpponentPaddle.h > 599)
    {
        OpponentPaddle.y = 599 - OpponentPaddle.h;
    }

    if(Ball.y < 1 || Ball.y + Ball.h > 599)
    {
        velY *= -1;
    }

    if(Ball.x < 2 || Ball.x + Ball.w > 798)
    {
        if(Ball.x < 2)
        {
            OpponentScore += 1;
        }
        else
        {
            MyScore += 1;
        }
        ResetBall();
    }

    if(OpponentPaddle.y + (0.5 * OpponentPaddle.h) > Ball.y + (0.5 * Ball.h))
    {
        OpponentPaddle.y -= abs(velY);
    }

    if(OpponentPaddle.y + (0.5 * OpponentPaddle.h) < Ball.y + (0.5 * Ball.h))
    {
        OpponentPaddle.y += abs(velY);
    }

    if(CollisionChecker(Ball, MyPaddle) || CollisionChecker(Ball, OpponentPaddle))
    {
        velX *= -1;

        int deltaX = velX/abs(velX);
        int deltaY = velY/abs(velX);
        velX += (deltaX);
        velY += (deltaY); 
    }

    if(OpponentScore > MyScore + 3)
    {
        MyPaddle.h = 100*2.5;
    }

    if(OpponentScore + 3 < MyScore)
    {
        OpponentPaddle.h = 100*2.5;
    }

    if(abs(OpponentScore - MyScore) < 3)
    {
        MyPaddle.h = 100;
        OpponentPaddle.h = 100;
    }

    Ball.x += velX;
    Ball.y += velY; 
}
