#include "Music.hpp"

Music::Music()
{
 SDL_Init(SDL_INIT_AUDIO);

 int rate = MIX_DEFAULT_FREQUENCY;
 Uint16 format = AUDIO_S16SYS;
 int channels = 2;
 int buffers = 4096;

 if (!Mix_OpenAudio(rate,format,channels,buffers))
 {
  cout << "Couldn't initialise audio:" << Mix_GetError() << endl;
  exit(0);
 }
}

Music::~Music()
{
 Mix_Quit();
}

void Music::playmusic(const char* path, int loops)
{
 Mix_Music* m = Mix_LoadMUS(path);
 if (m== nullptr)
 {
  cout << Mix_GetError();
 }
 Mix_PlayMusic(music, -1);
}

void Music::playchannel(int channel, const char *path, int loops)
{
 Mix_Chunk* s = Mix_LoadWAV(path);

    if (s == nullptr)
    {
        cout << "Couldn't init audio:" << Mix_GetError()<<endl;
    }

 if(Mix_PlayChannel(channel, sound, loops) == -1)
 {
  cout << "Error playing sound" << endl;
 }
}