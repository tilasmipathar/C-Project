#include<bits/stdc++.h>
using namespace std;

void LoadGame()
{
    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2
    TTF_Init();
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Ping Pong Ball",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        800,                               // width, in pixels
        600,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    screen = SDL_GetWindowSurface(window);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //--------------------------
    SDL_Surface* tempS = IMG_Load("PingPongBall/AI(final)/bkg.jpg");
    bckgrd = SDL_CreateTextureFromSurface(render, tempS);
    SDL_FreeSurface(tempS);

    //--------------------------

    MyPaddle.x = 20;
    MyPaddle.y = 250;
    MyPaddle.h = 100;
    MyPaddle.w = 20;

    OpponentPaddle.x = 760;
    OpponentPaddle.y = 250;
    OpponentPaddle.h = 100;
    OpponentPaddle.w = 20;

    Ball.x = ball_x;
    Ball.y = ball_y;
    Ball.h = 10;
    Ball.w = 10;

    srand(time(NULL));

    ResetBall();

    DispFont = TTF_OpenFont("PingPongBall/AI(final)/Zfont.ttf", 50);
    if(DispFont == NULL)
    {
        cout<<TTF_GetError()<<endl;
    }

    // BackgroundMusc = Mix_LoadMUS("bgm.mp3");
    // SoundEff = Mix_LoadWAV("sef.wav"); 

    MyScoreBox.x = 50;
    MyScoreBox.y = 30;
    MyScoreBox.w = 100;
    MyScoreBox.h = 50; 
    OppScoreBox.x = 725;
    OppScoreBox.y = 30;
    OppScoreBox.w = 100;
    OppScoreBox.h = 50;
    // velX = GenerateRandomNum(2, -2);
    // velY = GenerateRandomNum(2, -2);

}
