/*CLASS PINBALL*/
class Brickbreaker
{
    private:
        bool isRunning;
        SDL_Window *gamewindow;
        SDL_Renderer *gamerenderer;
        SDL_Rect* paddle;
        ball* gameball;
        int score;

    public:
        Brickbreaker();
        ~Brickbreaker();

        void init(char *title, int xcor, int ycor, int width, int height, bool fscr);
        void eventhandling();
        void update();
        void render();
        void clean();
        void input();
        void gameoverevent();
        void gameoverscreen();
        void winevent();
        void winscreen();
        int getscore();
        void setscore(int scr);
        bool running();
};