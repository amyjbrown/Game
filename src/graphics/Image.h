/**
  * @file Image.h
*/

#ifndef GAME_IMAGE_H
#define GAME_IMAGE_H

// tempt for cheating sake
// TODO: remove this when proper installation
#include <SDL_render.h>

namespace graphics {
    /// @brief Wrapper around an SDL_Texture pointer
    class Image final
    {
    public:
        explicit Image(SDL_Texture&) noexcept;
        Image(SDL_Texture&, SDL_Rect clip) noexcept;
        /// @brief Borrow pointer to texture for operations.
        [[nodiscard]]
        auto texture() const noexcept -> SDL_Texture*;
    private:
        SDL_Texture* texture_;
        SDL_Rect clip;
    };
};

#endif //GAME_IMAGE_H
