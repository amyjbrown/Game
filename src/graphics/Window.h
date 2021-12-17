/**
  * @file Window.h
  * @brief
  * @author Amy Brown 
*/

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <cstddef>
#include <SDL.h>
#include <SDL_render.h>

#include "Image.h"

namespace graphics {
    class Window
    {
    public:
        Window() = delete;
        /**
         * @brief Create and initialize a window
         * @param title   Title for the window
         * @param w       Width of window
         * @param h       Height of window
         * @return `true` if setup succeeded, `false` otherwise
         */
        static auto init(const char* title, int w, int h) -> bool;
        /**
         * @brief Blit an image onto the screen
         * @param image Source image to blit, holds it's own clipping rect
         * @param target position to blit image onto
         * */
        static void blit(const Image& image ,SDL_Rect target);
        /**
         * @brief Get a pointer to Window's renderer, panics if uninitialized
         * */
        static auto borrow_render() -> SDL_Renderer*;
        /// @brief Shutdown window context and free resources
        static void shutdown();
        /// @brief Clears and shows buffer
        static void flip();

    private:
        static bool initialized;
        static SDL_Renderer* renderer;
        static SDL_Window* window;
        // static SDL_Texture* texture;
    };
}

#endif //GAME_WINDOW_H
