#pragma once
#include "SDL.h"

struct Vector2
{
	float x;

	float y;

	Vector2(float xside, float yside) {
		x = xside;
		y = yside;
	}
};

struct Resolution { 
	float width{ 800 };
	float height{ 600 };
	int pos_x{ 100 };
	int pos_y{ 100 };
};

class Game {
public:
	//game initializer
	bool Initialize();

	//run game loop until game is over
	void Runloop();

	//shutdown the game
	void Shutdown();

private:
	
	//screen resolution
	Resolution res;

	//helper functions for game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();


	//Window created by SDL
	SDL_Window* mWindow;

	//renderer for creating pictures
	//renderer created with SDL, we can also use OPEN_GL
	SDL_Renderer* mRenderer;

	//game should continue to run?
	bool mIsRunning;

	//paddle and ball
	Vector2 mPaddlePos{ 0, (res.height/2) };
	Vector2 mBallPos{ (res.width/2), (res.height/2) };
	Vector2 mBallVel{ -200.0f, 235.0f };

	/* ======= USEFUL VARIABLES ======== */
	const int thickness{ 12 };  
	const int lenght_of_paddle{ 8 };
	const int paddleH{ lenght_of_paddle * thickness };
	
	//state variable used to get keyboard state function
	//implementation - ProcessInput()
	const Uint8* state = SDL_GetKeyboardState(NULL);

	//variable used to calculate delta time
	//implementation - UpdateGame()
	Uint32 mTicksCount{ 0 };

	//variable for paddle movement
	//used in ProcessInput()
	int mPaddleDir{ 0 };

	

	/*========================================*/
};