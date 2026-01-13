#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Button
{
private:

	//SDL_FRect buttonChangeColorRect;
	//SDL_Color buttonChangeColorColor;

	//SDL_FRect buttonQuitRect;
	//SDL_Color buttonQuitColor;

	SDL_FRect m_rect;
	SDL_Color m_color;

public:

	Button(SDL_FRect rect, SDL_Color color) : m_rect(rect), m_color(color) {}

	void isPressed(float mouseX, float mouseY, bool mousePress);

	void Draw();



};
