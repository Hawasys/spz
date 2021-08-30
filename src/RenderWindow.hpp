#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <ostream>

class RenderWindow
{
    public:
        RenderWindow(const char* win_title, int win_w, int w_h);
        SDL_Texture* LoadTexture(const char* w_filepath);
        void cleanup();
        void clear();
        void render(SDL_Texture* w_tex);
        void display();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
