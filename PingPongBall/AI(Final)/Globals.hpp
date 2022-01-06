

const int ball_x = 395;
const int ball_y = 295;
SDL_Color white = {255, 255, 255, 255};
SDL_Color pink = {255, 0, 255};

SDL_Surface* screen;
SDL_Renderer *render;
SDL_Event occur;

SDL_Texture * tex1;
SDL_Texture * tex2;
SDL_Texture* bckgrd;

// Mix_Music* BackgroundMusc;
// Mix_Chunk* SoundEff; 

SDL_Rect MyPaddle;
SDL_Rect OpponentPaddle;
SDL_Rect Ball;

int MyScore = 0;
int OpponentScore = 0;

SDL_Rect MyScoreBox;
SDL_Rect OppScoreBox;

int velX;
int velY;

TTF_Font* DispFont;
