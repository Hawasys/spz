#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <ostream>

#include "RenderWindow.hpp"
#include "usf.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char *argv[])
{
    SDL_Event event;
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        print_error();
    if(!IMG_Init(IMG_INIT_PNG))
        print_error();

    RenderWindow window("TEST v1", 1280, 720);
    
    bool gameRunning = true;    
    
    while (gameRunning){
        SDL_WaitEvent(&event);
        if(event.type == SDL_QUIT)
            gameRunning=false;
    }

    window.cleanup();
    SDL_Quit();
    return 0;
}

