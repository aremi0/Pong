#pragma once
class Ball {
protected:
	float x, y;
	float speedX, speedY;
	float radius;

public:
	Ball(float x, float y, float rad);
	void draw();
	void move(float velocity);
	void checkLimits();
	void checkCollisions(Rectangle playerSX, Rectangle playerDX, Sound fx);
	const char* handleWinner(int& dxWin, int& sxWin);
};

