#include <SDL3/SDL.h>
#include "Button.h"

int main()
{
    SDL_Window* window = SDL_CreateWindow("Button", 800, 600, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
	bool isOpen = true;


	/*SDL_FRect buttonChangeColorRect = {300, 275, 200, 50};
	SDL_Color buttonChangeColorColor = {255, 255, 255, 255};*/

	/*SDL_FRect buttonQuitRect = {300, 475, 200, 50};
	SDL_Color buttonQuitColor = {255, 0, 0, 255};*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Button button1({ 300, 275, 200, 50 }, { 255, 255, 255, 255 });
	Button button2({ 300, 475, 200, 50 }, { 255, 0, 0, 255 });

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	SDL_Color clearColor = {0, 0, 0, 255};

	while (isOpen) {
		bool mousePress = false;
		float mouseX = 0;
		float mouseY = 0;

		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_EVENT_QUIT)
			{
				isOpen = false;
			}
			if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)
			{
				isOpen = false;
			}
			if (e.type == SDL_EVENT_MOUSE_BUTTON_UP && e.button.button == SDL_BUTTON_LEFT) {
				mousePress = true;
				mouseX = e.button.x;
				mouseY = e.button.y;
			}
		}

		button1.isPressed(mouseX, mouseY, mousePress);

		/*if (mouseX >= buttonChangeColorRect.x && mouseX <= buttonChangeColorRect.x + buttonChangeColorRect.w
			&& mouseY >= buttonChangeColorRect.y && mouseY <= buttonChangeColorRect.y + buttonChangeColorRect.h
			&& mousePress)
		{
			if (clearColor.r == 0 && clearColor.g == 0 && clearColor.b == 0) {
				clearColor = { 0,255, 255, 255 };
			}
			else if (clearColor.r == 0 && clearColor.g == 255 && clearColor.b == 255) {
				clearColor = { 255, 255, 0, 255 };
			}
			else if (clearColor.r == 255 && clearColor.g == 255 && clearColor.b == 0) {
				clearColor = { 0, 0, 0, 255 };
			}
		}*/

		if (mouseX >= buttonQuitRect.x && mouseX <= buttonQuitRect.x + buttonQuitRect.w
			&& mouseY >= buttonQuitRect.y && mouseY <= buttonQuitRect.y + buttonQuitRect.h
			&& mousePress)
		{
			isOpen = false;
		}

		SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, buttonChangeColorColor.r, buttonChangeColorColor.g, buttonChangeColorColor.b, buttonChangeColorColor.a);
		SDL_RenderFillRect(renderer, &buttonChangeColorRect);

		SDL_SetRenderDrawColor(renderer, buttonQuitColor.r, buttonQuitColor.g, buttonQuitColor.b, buttonQuitColor.a);
		SDL_RenderFillRect(renderer, &buttonQuitRect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}