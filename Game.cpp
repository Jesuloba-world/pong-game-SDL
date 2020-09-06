#include "Game.h"

// game starter
bool Game::Initialize() 
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);

	if (sdlResult != 0) 
	{
		SDL_Log("unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	//create game window
	mWindow = SDL_CreateWindow(
		"Jesuloba's Pong game (my first game project)", //Windows title
		res.pos_x,	//Top left x-coordinate of window
		res.pos_y,	//Top left y-coordinate of window
		res.width,	//Width of the window
		res.height,	//Height of the window
		0		//flags (0 means no flags set)
	);

	if (!mWindow) 
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	
	//create game renderer
	mRenderer = SDL_CreateRenderer(
		mWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	mIsRunning = true;

	return true;
}




//game quitter
void Game::Shutdown() 
{
	SDL_DestroyRenderer(mRenderer);

	SDL_DestroyWindow(mWindow);

	SDL_Quit();
}




//main game loop
void Game::Runloop() 
{
	while (mIsRunning) 
	{
		
		ProcessInput();

		UpdateGame();

		GenerateOutput();
	}
}

