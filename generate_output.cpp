#include "Game.h"


void Game::GenerateOutput()
{
	//set renderer default color
	SDL_SetRenderDrawColor(
		mRenderer,
		0,		//R
		0,		//G
		255,	//B
		255		//A
	);

	//clear back buffer
	SDL_RenderClear(mRenderer);

	//draw filled rectangle for PONG
	//colour for rectangles
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

	//up wall
	SDL_Rect wall1{
		0,			//top left x
		0,			//top left y
		res.width,		//width
		thickness	//height
	};
	SDL_RenderFillRect(mRenderer, &wall1);

	//down wall
	SDL_Rect wall2{
		0,							//top left x
		res.height - thickness,		//top left y
		res.width,					//width
		thickness					//height	
	};
	SDL_RenderFillRect(mRenderer, &wall2);

	//right side wall
	SDL_Rect wall3{
		res.width - thickness,	//top left x
		0,		//top left y
		thickness,	//width
		res.height			//height
	};
	SDL_RenderFillRect(mRenderer, &wall3);

	
	//changing renderer draw colour for ball and paddle
	SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);


	//The ball default position
	SDL_Rect ball{
		static_cast <int> (mBallPos.x - thickness / 2),
		static_cast <int> (mBallPos.y - thickness / 2),
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);

	//The paddle default position
	SDL_Rect paddle{
		static_cast <int> (mPaddlePos.x + thickness / 2),
		static_cast <int> (mPaddlePos.y - (paddleH / 2)),
		thickness,
		paddleH
	};
	SDL_RenderFillRect(mRenderer, &paddle);

	//swap back and front buffer
	SDL_RenderPresent(mRenderer);
}

