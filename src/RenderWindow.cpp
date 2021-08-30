#include "RenderWindow.hpp"
#include "usf.hpp"
#include <ostream>


RenderWindow::RenderWindow(const char* win_title, int win_w, int win_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(win_title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_w, win_h, SDL_WINDOW_SHOWN);
    if(window == NULL)
        print_error();
    
    renderer: SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanup()
{
    SDL_DestroyWindow(window);
}
