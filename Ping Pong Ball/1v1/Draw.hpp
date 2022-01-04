#include<bits/stdc++.h>
using namespace std;


void DrawScreen()
{
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderDrawRect(render, &MyPaddle);
    SDL_RenderFillRect(render, &MyPaddle);
    
    SDL_RenderDrawRect(render, &OpponentPaddle);
    SDL_RenderFillRect(render, &OpponentPaddle);
    
    SDL_RenderDrawRect(render, &Ball);
    SDL_RenderFillRect(render, &Ball);


    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

    stringstream mySc;
    stringstream oppSc;

    mySc << MyScore;
    oppSc << OpponentScore;

    SDL_Surface* MyScSurface = TTF_RenderText_Solid(DispFont, mySc.str().c_str(), white);
    SDL_Surface* OppScSurface= TTF_RenderText_Solid(DispFont, oppSc.str().c_str(), white);

    if(MyScSurface == NULL || OppScSurface == NULL)
    {
        cout<<TTF_GetError();
    }


    // SDL_BlitSurface(MyScSurface, NULL, screen, &MyScoreBox);
    // SDL_BlitSurface(OppScSurface, NULL, screen, &OppScoreBox);
    tex1 = SDL_CreateTextureFromSurface(render, MyScSurface);
    tex2 = SDL_CreateTextureFromSurface(render, OppScSurface);

    SDL_QueryTexture(tex1, nullptr, nullptr, &MyScoreBox.w, &MyScoreBox.h);
    SDL_QueryTexture(tex2, nullptr, nullptr, &OppScoreBox.w, &OppScoreBox.h);

    // SDL_DestroyTexture(tex1);
    // SDL_DestroyTexture(tex2);

    SDL_FreeSurface(MyScSurface);
    SDL_FreeSurface(OppScSurface);

    SDL_RenderPresent(render);
}