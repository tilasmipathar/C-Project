#include "Game.h"
#include "TextManager.hpp"
#include "Map.hpp"
#include "ECS/Components.h"

Map *gamemap;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
//auto& player(manager.addEntity());

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
		}

		isRunning = true;
	} 


	gamemap = new Map();
// 
	// player.addComponent<PositionComponent>();
	// player.addComponent<SpriteComponent>("../assets/char.png");
// 
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();
		
	// if(player.getComponent<PositionComponent>().x()>120)
	// player.getComponent<SpriteComponent>().setTex("../assets/assassin.png");
}

void Game::render()
{
	SDL_RenderClear(renderer);
	gamemap->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

/*void Game::AddTile(int id,int x,int y){
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>()
}
*/