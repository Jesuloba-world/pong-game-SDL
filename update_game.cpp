#include "Game.h"


void Game::UpdateGame()
{
	//wait until 16ms has elapsed since the last frame
	//basically limiting framerate to 60FPS	
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
		;

	//Delta time is the difference in ticks from last frame (converted to seconds)
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

	//clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	//update tick counts (for next frame)
	mTicksCount = SDL_GetTicks();

	//paddle position updater
	if (mPaddleDir != 0)
	{
		mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;

		// To make sure paddle doesn't go of screen
		if (mPaddlePos.y < ((paddleH / 2.0f) + thickness))
		{
			mPaddlePos.y = paddleH / 2.0f + thickness;
		}
		else if (mPaddlePos.y > (res.height - paddleH / 2.0f - thickness))
		{
			mPaddlePos.y = res.height - paddleH / 2.0f - thickness;
		}

	}

	//making the ball move
	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;

	//making the ball bounce off the walls
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f)
	{
		mBallVel.y *= -1;
	}
	if (mBallPos.y >= (res.height - thickness) && mBallVel.y > 0.0f)
	{
		mBallVel.y *= -1;
	}
	if (mBallPos.x >= (res.width - thickness) && mBallVel.x > 0.0f)
	{
		mBallVel.x *= -1;
	}


	float y_diff{ (mPaddlePos.y - ((paddleH) / 2)) - (mBallPos.y - thickness / 2) };

	if (y_diff < 0)
	{
		y_diff *= -1;
	}


	//ball bouncing off the paddle
	if (
		// our y-difference is small enough
		y_diff <= paddleH &&
		// ball is at the correct x position
		mBallPos.x <= 20.0f && mBallPos.x >= 15.0f &&
		// the ball is moving to the left
		mBallVel.x < 0.0f
		)
	{
		mBallVel.x *= -1;
	}
}