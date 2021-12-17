#include <iostream>

#include <SDL.h>

#include "graphics/Window.h"

int main(int argc, char* args[]) {
    using namespace graphics;

    SDL_Init(SDL_INIT_EVERYTHING);
    Window::init(
            "Test!",
            360,
            480
            );
    for(;;)
    {
        SDL_Event eventum;
        while (SDL_PollEvent(&eventum))
        {
            if (eventum.type == SDL_QUIT) goto quit;
        };
        Window::flip();
    }

    quit:

    Window::shutdown();
    SDL_Quit();
    return 0;
}
