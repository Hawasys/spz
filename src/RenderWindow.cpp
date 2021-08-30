#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* w_title, int w_w, int w_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(w_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w_w, w_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::LoadTexture(const char* w_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, w_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::cleanup()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* w_tex)
{
	SDL_RenderCopy(renderer, w_tex, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

