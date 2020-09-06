#include "Game.h"

// input processor
void Game::ProcessInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//if this is a SDL_quit event, end loop
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	//get keyboard state
	//const Uint8* state = SDL_GetKeyboardState(NULL);

	//if escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}

	//movement of paddle with W and S
	mPaddleDir = 0;
	if (state[SDL_SCANCODE_W])
	{
		mPaddleDir -= 1;
	}

	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
	}

}
