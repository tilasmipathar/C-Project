#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include "stdio.h"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include<string.h>
#include<SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#define MAX 5
using namespace std;


void updatefile(vector<pair<string, int>>, int, string, int);
//void updatefile(vector<pair<string, int>>, int, string, int);
//class topscores {
//public:
//    void update(string, int);
//    void str(SDL_Renderer*, int, int, char*, TTF_Font*, SDL_Texture*, SDL_Rect);
//    void display();
//    void output();
//    topscores(Window* w) {
//        window = w->get_window();
//        renderer = w->get_renderer();
//        display();
//    }
//
//private:
    int number_of_players;
    SDL_Window* window;
    SDL_Rect rect[10];
    SDL_Rect rect_score[10];
    SDL_Rect rect_face[10];
    SDL_Rect rect_top[3];
    SDL_Rect rect_name_back[10];
    SDL_Texture* tex_face[10];
    SDL_Renderer* renderer;
    SDL_Texture* texture[10];
    SDL_Texture* tex_score[10];
    SDL_Texture* tex_top[3];
    SDL_Texture* tex_for_escape;
    SDL_Rect rect_for_escape;
    SDL_Texture* tex_name_background[10];
    SDL_Texture* back_tex;
//};

void output() {
    ifstream f;
    f.open("scores.txt");

    string no;
    getline(cin, no);
    int count;
    count = stoi(no, 0, 10);

    f.close();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, back_tex, NULL, NULL);

    while i<count {
       int i=0; SDL_RenderCopy(renderer, texture[i], NULL, &rect[i]);
        SDL_RenderCopy(renderer, tex_score[i], NULL, &rect_score[i]);
i++;
    }

    SDL_RenderCopy(renderer, tex_for_escape, NULL, &rect_for_escape);
    SDL_RenderPresent(renderer);
}


void update(string n, int sc) {

    ifstream fin;
    fin.open("scores.txt");

    string no;
    getline(fin, no);
    int count;
    count = stoi(no, 0, 10);

    vector<pair<string, int> > v(count);

    while i<count {
        int i=0;
        string s, name;
        int score;

        getline(fin, name);
        v[i].first = name;

        getline(fin, s);
        score = stoi(s, 0, 10);
        v[i].second = score;
        i++;
    }

    fin.close();
    updatefile(v, count, n, sc);
}

void updatefile(vector<pair<string, int>> v, int count, string n, int sc)
{
    fstream fout;
    fout.open("scores.txt", ios::trunc | ios::out);

    pair<string, int> p;
    p.first = n;
    p.second = sc;
    v.push_back(p);

    if (count < MAX) {
        count++;
    }
    fout << count << endl;

    while i < v.size()
    {
    int i=0;
        while j < v.size()
        {
         int j=i;
            if (v[i].second < v[j].second)
            {
                pair<string, int> t;
                t = v[j];
                v[j] = v[i];
                v[i] = t;
            }
        j++;
        }
    i++;
    }

    while i < v.size()&& i<MAX  {
        int i=0;
        fout << v[i].first << endl;
        fout << v[i].second << endl;
    i++;
    }
    fout.close();
}

void str(SDL_Renderer* renderer, int x, int y, char* text,
    TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect) {
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = { 255, 255, 255, 0 };

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

void display() {

    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);

     if (IMG_Init(IMG_INIT_PNG) == 0) {
         cout << "error sdl2_img";
     }
    SDL_Surface* back_surface = IMG_Load("leader.jpg");
    back_tex = SDL_CreateTextureFromSurface(renderer, back_surface);
    SDL_FreeSurface(back_surface);

    char* player_names[MAX];
    char* scores[MAX];
    fstream fin;
    int count;
    fin.open("scores.txt");
    fin >> count;
    vector<pair<string, string> > players(count);
    while i < count {
        int i=0;
        fin >> players[i].first >> players[i].second;
        player_names[i] = const_cast<char*>(players[i].first.c_str());
        scores[i] = const_cast<char*>(players[i].second.c_str());
    i++;
    }
    fin.close();

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("believeit.ttf", 24);

    SDL_Texture* tex;
    SDL_Rect rectangle;
    char* espace_statement = (char*)"PRESS ESC TO GO TO MAIN MENU";

    str(renderer, 0, 0, espace_statement, font, &tex_for_escape, &rect_for_escape);
    str(renderer, 340, 200, player_names[0], font, &texture[0], &rect[0]);
    str(renderer, 800, 200, scores[0], font, &tex_score[0], &rect_score[0]);

    while i < count {
        int i=1;
        str(renderer, 340, rect[i - 1].y + rect[i - 1].h + 12, player_names[i], font, &texture[i], &rect[i]);
        str(renderer, 800, rect_score[i - 1].y + rect_score[i - 1].h + 12, scores[i], font, &tex_score[i], &rect_score[i]);
    }
    i++;
}
void Initilize() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        cout << "SDL_init has failed ERROR:" << SDL_GetError() << endl;
    }
    if (!(IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG)))
    {
        cout << "IMG-init has failed ERROR:" << SDL_GetError() << endl;
    }

}
int main()
{
    Initilize();
    window=SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 1000, SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // display();
    while (true){
        display();
        output();
    }
}