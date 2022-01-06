/*Brickbreaker functions*/
#include "header.hpp"

using namespace std;

//Global vars
bool velflag = true;
bool spaceflag = false;
bool gameoverflag = false;
bool winflag = false;
int SPEED = 16;

//Constructor
Brickbreaker::Brickbreaker()
{
    paddle = new SDL_Rect();
};

//Destructor
Brickbreaker::~Brickbreaker(){};

//Returns the score of the game
int Brickbreaker::getscore()
{
    return score;
}

//To change the score of the game
void Brickbreaker::setscore(int scr)
{
    this->score = scr;
}

//If the game is either won or lost: this screen displays the score
void aftergamescreen(SDL_Renderer* gamerenderer, char* mess, int score)
{
    SDL_Rect aftergame;
    aftergame.w = 640;
    aftergame.h = 480;
    aftergame.x = 320;
    aftergame.y = 240;
    SDL_RenderDrawRect(gamerenderer, &aftergame);
    SDL_SetRenderDrawColor(gamerenderer, 0, 0, 0, 255);
    SDL_RenderFillRect(gamerenderer, &aftergame);
    SDL_SetRenderDrawColor(gamerenderer,255, 255, 255, 255);

    //Prints whether the game is won or lost
    TTF_Font* Sans = TTF_OpenFont("brickbreaker/assets/SansSerif.ttf", 72);
    SDL_Color color = {255, 0, 0, 255};
    SDL_Surface* message = TTF_RenderText_Solid(Sans, mess, color);
    SDL_Texture* messagetext = SDL_CreateTextureFromSurface(gamerenderer, message);
    SDL_Rect Message_rect;
    Message_rect.x = 384+32;
    Message_rect.y = 304;
    Message_rect.w = 512;
    Message_rect.h = 128;
    SDL_QueryTexture(messagetext, nullptr, nullptr, &Message_rect.w, &Message_rect.h); 
    SDL_RenderCopy(gamerenderer, messagetext, NULL, &Message_rect);

    //Tells the score
    Sans = TTF_OpenFont("brickbreaker/assets/SansSerif.ttf", 24);
    int a = score;
    char b[100];
    color = {0, 255, 0, 255};
    sprintf(b, "Your Score is:  %d", a);
    message = TTF_RenderText_Solid(Sans, b, color);
    messagetext = SDL_CreateTextureFromSurface(gamerenderer, message);
    Message_rect.x = 384+32+128;
    Message_rect.y = 304+128;
    Message_rect.w = 512;
    Message_rect.h = 128;
    SDL_QueryTexture(messagetext, nullptr, nullptr, &Message_rect.w, &Message_rect.h); 
    SDL_RenderCopy(gamerenderer, messagetext, NULL, &Message_rect);

    //Indicates the commands of replaying the game or exiting it to the player
    Sans = TTF_OpenFont("brickbreaker/assets/SansSerif.ttf", 24);
    color = {0, 0, 255, 255};
    message = TTF_RenderText_Solid(Sans, "Press SPACE to play again or press ESC to Exit", color);
    messagetext = SDL_CreateTextureFromSurface(gamerenderer, message);
    Message_rect.x = 384+32;
    Message_rect.y = 304+128+128;
    Message_rect.w = 512;
    Message_rect.h = 128;
    SDL_QueryTexture(messagetext, nullptr, nullptr, &Message_rect.w, &Message_rect.h); 
    SDL_RenderCopy(gamerenderer, messagetext, NULL, &Message_rect);
}

//The case in which all bricks are broken and the player wins the game
void Brickbreaker::winevent()
{
    if(getscore()==68)
    {
        winflag = true;
    }
}

//The action taken when the player wins the game
void Brickbreaker::winscreen()
{
    char b[100] = "YOU WIN!!";
    aftergamescreen(gamerenderer, b, getscore());
}

//The case in which the ball goes below the paddle and player loses
void Brickbreaker::gameoverevent()
{
    if(gameball->getpos()->pos->y+16>=960)
    {
        gameoverflag = true;
    }
}

//Action taken when the player loses
void Brickbreaker::gameoverscreen()
{
    char b[100] = "GAME OVER...";
    aftergamescreen(gamerenderer, b, getscore());
}

//Initialising the game
void Brickbreaker::init(char *title, int xcor, int ycor, int width, int height, bool fscr)
{
    //Initialising SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        cout << "Initialised!" << endl;
        if(fscr) gamewindow = SDL_CreateWindow(title, xcor, ycor, width, height, SDL_WINDOW_FULLSCREEN);
        else gamewindow = SDL_CreateWindow(title, xcor, ycor, width, height, 0);

        if(gamewindow) cout << "Window created" << endl;

        gamerenderer = SDL_CreateRenderer(gamewindow, -1, 0);

        if(gamerenderer)
        { 
            cout << "Renderer created" << endl;
            SDL_SetRenderDrawColor(gamerenderer, 255, 255, 255, 255);
        }
        
        isRunning = true;
    }
    else isRunning = false;

    //Initialising TTF for text rendering
    if(TTF_Init()<0)
    {
        cerr << TTF_GetError() << endl;
    }

    //Setting the initial score to 0
    setscore(0);

    //Initialising the paddle
    paddle->x = 512;
    paddle->y = 848;
    paddle->w = 288;
    paddle->h = 8;
    SDL_RenderDrawRect(gamerenderer, paddle);
    SDL_SetRenderDrawColor(gamerenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(gamerenderer, paddle);

    //Initialising the ball;
    gameball = new ball(16, 16, 640, 832, 0, 0);
    
    //Rendering all the bricks and textures
    textinit(gamerenderer);

    //Initialising all the brick rectangles
    bricks();
};

//Eventhandling
void Brickbreaker::eventhandling()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
};

//Manages keyboard input
void Brickbreaker::input()
{
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e)) if(e.type==SDL_QUIT);

    //If the game is going on, to move the paddle left
    if(keystates[SDL_SCANCODE_LEFT] && !winflag && !gameoverflag) 
    {
        if(!spaceflag && paddle->x>0) gameball->getpos()->pos->x-=SPEED;
        if(paddle->x>0)paddle->x-=SPEED;
        SDL_RenderDrawRect(gamerenderer, paddle);
        SDL_RenderFillRect(gamerenderer, paddle);
    }
    //If the game is going on, to move the paddle right
    if(keystates[SDL_SCANCODE_RIGHT] && !winflag && !gameoverflag) 
    {
        if(!spaceflag && paddle->x+paddle->w<1280) gameball->getpos()->pos->x+=SPEED;
        if(paddle->x+paddle->w<1280)paddle->x+=SPEED;
        SDL_RenderDrawRect(gamerenderer, paddle);
        SDL_RenderFillRect(gamerenderer, paddle);
    }
    //To release the ball from the paddle initially
    if(keystates[SDL_SCANCODE_UP] && !winflag && !gameoverflag)
    {
        spaceflag = true;
    }
    //When the game is over, if player wants to exit the game
    if(keystates[SDL_SCANCODE_ESCAPE]) 
    {
        isRunning = false;
    }
    //If the player wants to replay the game
    if(keystates[SDL_SCANCODE_SPACE]) 
    {
        //Reseting and reinitialising all the important variables to start the game again
        velflag = true;
        spaceflag = false;
        gameoverflag = false;
        winflag = false;
        setscore(0);
        textinit(gamerenderer);
        paddle->x = 512;
        paddle->y = 848;
        SDL_RenderDrawRect(gamerenderer, paddle);
        SDL_SetRenderDrawColor(gamerenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(gamerenderer, paddle);
        gameball = new ball(16, 16, 640, 832, 0, 0);
    }
}

//Keeping updates of the events happening in the game
void Brickbreaker::update()
{
    //If the game is being played
    if(!gameoverflag && !winflag)
    {
        //If the ball is released
        if(spaceflag && velflag)
        {
            gameball->getpos()->vel->x=16;
            gameball->getpos()->vel->y=-8;
            velflag = false;
        }
        
        //Updating the score
        int a = getscore();
        setscore(checkcollisions(gameball, a));

        //Updating velocity and cordinates of the ball
        gameball->updatecord();
        gameball->updatevel(paddle);

        //Checking if the game is won or lost
        gameoverevent();
        winevent();
    }
};

//Rendering everything
void Brickbreaker::render()
{
    //Clearing the buffer of the renderer
    SDL_RenderClear(gamerenderer);

    //render the background
    bckgrdload(gamerenderer);

    //If the game is neither over nor won
    if(!gameoverflag && !winflag)
    {
        //Rendering the textures, ball, and paddle
        textrender(gamerenderer);
        ballrender(gamerenderer, gameball->gettexture(), gameball->getpos());
        SDL_RenderDrawRect(gamerenderer, paddle);
        SDL_RenderFillRect(gamerenderer, paddle);
    }
    //If the game is won, initiating the action to winning the game
    if(winflag)
    {
        winscreen();
    }
    //If the game is lost, initiating the action to losing the game
    if(gameoverflag)
    {
        gameoverscreen();
    }
    //To present everything in the buffer
    SDL_RenderPresent(gamerenderer);
};

//Cleaning the game after quiting
void Brickbreaker::clean()
{
    SDL_DestroyWindow(gamewindow);
    SDL_DestroyRenderer(gamerenderer);
    SDL_Quit();
    cout << "Game clean and closed" << endl;
};

//Returning whether the game is running or not
bool Brickbreaker::running()
{
    return isRunning;
}