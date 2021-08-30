#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
    public:
        RenderWindow(const char* win_title, int win_w, int w_h);
        void cleanup();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
