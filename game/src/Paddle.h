#pragma once

enum movement {
	UP,
	DOWN
};

class Paddle {
protected:
	float x, y;
	float speed;
	float width, height;

public:
	Paddle(float x, float y, float width = 10, float height = 100, float speed = 500);
	Rectangle getRect();
	void draw();
	void move(movement m, float velocity);
};

