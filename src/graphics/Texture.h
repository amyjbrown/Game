/**
  * @file Texture.h
  * @brief
  * @author Amy Brown 
*/

#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H
#include <SDL.h>
#include <SDL_render.h>

namespace graphics {
    class Texture
    {
    public:
        explicit Texture(SDL_Texture&) noexcept;
    private:
        SDL_Texture* texture;
    };
}


#endif //GAME_TEXTURE_H
