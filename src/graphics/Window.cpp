/**
  * @file Window.cpp
  * @brief
  * @author Amy Brown 
*/

#include <SDL_log.h>
#include <SDL_assert.h>

#include "Window.h"
using namespace graphics;

bool Window::initialized = false;
SDL_Renderer* Window::renderer = nullptr;
SDL_Window* Window::window = nullptr;

auto Window::init(const char *title, int w, int h) -> bool {
    if (initialized) {
        SDL_Log("Initialization already performed");
        return true;
    }
    SDL_ClearError();

    auto wnd = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            w,
            h,
            0
    );

    if (wnd == nullptr) {
        SDL_Log("Failed to create window: %s\n", SDL_GetError());
        SDL_ClearError();
        return false;
    }
    auto re = SDL_CreateRenderer(wnd, -1, 0);
    if (re == nullptr) {
        SDL_Log("Failed to create renderer: %s\n", SDL_GetError());
        SDL_ClearError();
        return false;
    }
    // Perform misc setup
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(re,w,h);

    Window::renderer = re;
    Window::window = wnd;
    initialized = true;
    // Set "reasonable" background color
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    // Initially show something
    SDL_RenderPresent(renderer);

    return true;
}

auto Window::borrow_render() -> SDL_Renderer * {
    SDL_assert(initialized == true);
    return renderer;
}

void Window::blit(const Image &image, SDL_Rect target) {
    SDL_assert(initialized);

    auto clip = image.clip();
    SDL_RenderCopy(
            renderer,
            image.texture(),
            &clip,
            &target
            );
}

void Window::shutdown() {
    if (! initialized) {
        SDL_Log("The SDL context is not currently running.");
        return;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Log("Successfully shutdown SDL Window.");
}

void Window::flip() {
    SDL_assert(initialized);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}