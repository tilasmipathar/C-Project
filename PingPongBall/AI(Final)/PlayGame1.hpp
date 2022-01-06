void PlayGame1()
{
    LoadGame();
    bool running = true;

    while (running)
    {
        SDL_PollEvent(&occur);

        if(occur.type == SDL_QUIT)
        {
            running = false;
        }
        
		SDL_RenderClear(render);
        SDL_RenderCopy(render, bckgrd, NULL, NULL);
        SDL_RenderCopy(render, tex1, NULL, &MyScoreBox);
        SDL_RenderCopy(render, tex2, NULL, &OppScoreBox);

        Logic1();
        DrawScreen();
        
    }
}
