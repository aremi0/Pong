#include "raylib.h"
#include "Ball.h"
#include <random>

Ball::Ball(float x, float y, float rad) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator

	this->x = x;
	this->y = y;
	this->radius = rad;

	// La palla partirà in una direzione randomica ogni volta
	//----------------------------------------------------------------------------------
	std::uniform_int_distribution<> distrX(0, 1); // define the range
	this->speedX = distrX(gen) == 0 ? -300 : 300;

	std::uniform_real_distribution<float> distrY(-GetScreenHeight(), GetScreenHeight()); // define the range
	this->speedY = distrY(gen);
	//----------------------------------------------------------------------------------
}

void Ball::draw() {
	DrawCircle((int) x, (int) y, radius, WHITE);
}

void Ball::move(float velocity) {
	this->x += this->speedX * velocity;
	this->y += this->speedY * velocity;
	Ball::checkLimits();
}

void Ball::checkLimits() {
	if(this->y < 0) {
		this->y = 0;
		this->speedY *= -1;
	}
	if(this->y > GetScreenHeight()) {
		this->y = GetScreenHeight();
		this->speedY *= -1;
	}
}

void Ball::checkCollisions(Rectangle playerSX, Rectangle playerDX, Sound fx) 
{

	if(CheckCollisionCircleRec(Vector2 { this->x, this->y }, this->radius, playerSX)) 
	{
		if(this->speedX < 0) 
		{
			this->speedX *= -1.1f;
			this->speedY = (this->y - playerSX.y) / (playerSX.height / 2) * this->speedX;
		}
		PlaySound(fx);
	}

	if(CheckCollisionCircleRec(Vector2 { this->x, this->y }, this->radius, playerDX)) 
	{
		if(this->speedX > 0) 
		{
			this->speedX *= -1.1f;
			this->speedY = (this->y - playerDX.y) / (playerDX.height / 2) * -(this->speedX);
		}
		PlaySound(fx);
	}
}

const char* Ball::handleWinner(int& dxWin, int& sxWin) 
{
	if(this->x < 0)
	{
		dxWin++;
		return "Right Player Wins!";
	}

	if(this->x > GetScreenWidth())
	{
		sxWin++;
		return "Left Player Wins!";
	}

	return nullptr;
}