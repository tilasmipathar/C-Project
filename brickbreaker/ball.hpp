/*Ball class*/
#ifdef __gnu_linux__
#include "../SDL2/SDL.h"
#include "../SDL2_image/SDL_image.h"
#include "../SDL2_ttf/SDL_ttf.h"
#endif

//Vector
typedef struct
{
    int x, y;
}vect;

//Position and velocity vector
typedef struct 
{
    vect* pos, *vel;
}pos;

//Texture of ball
typedef struct
{
    double width, height;
    SDL_Rect* ballrect;
}texture;

//Ball class
class ball
{
    private:
        pos* ball_pos;
        texture* balltext;

    public:
        ball(int height, int width, int xcor, int ycor, int vxinit, int vyinit);
        void updatevel(SDL_Rect* paddle);
        void updatecord();
        pos* getpos();
        texture* gettexture();
};


 