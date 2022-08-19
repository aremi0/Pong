#include "raylib.h"
#include "Paddle.h"

Paddle::Paddle(float x, float y, float width, float height, float speed) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->speed = speed;
}

void Paddle::move(movement m, float velocity) {
	if(m == movement::UP)
		this->y -= this->speed * velocity;
	else if(m == movement::DOWN)
		this->y += this->speed * velocity;
}

Rectangle Paddle::getRect() {
	return Rectangle { this->x - this->width, this->y - this->height, this->width, this->height };
}

void Paddle::draw() {
	DrawRectangleRec(getRect(), WHITE);
}