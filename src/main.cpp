#include "RenderWindow.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char *argv[])
{
    SDL_Event event;
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; 
    if(!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
    RenderWindow window("TEST v1", 1280, 720);
    
    bool gameRunning = true;    
    SDL_Texture* grassTexture = window.LoadTexture("./res/gfx/ground_grass_1.png");
    while (gameRunning){
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning=false;
        }
        window.clear();
        window.render(grassTexture);
        window.display();
    }

    window.cleanup();
    SDL_Quit();
    return 0;
}
