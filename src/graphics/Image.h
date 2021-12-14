/**
  * @file Image.h
*/

#ifndef GAME_IMAGE_H
#define GAME_IMAGE_H

// tempt for cheating sake
// TODO: remove this when proper installation
struct SDL_Texture;


namespace graphics {
    /// @brief Wrapper around an SDL_Texture pointer
    class Image final
    {
    public:
        Image(SDL_Texture&) noexcept;
        /// @brief Borrow pointer to texture for operations.
        auto texture() const noexcept -> SDL_Texture*;
    private:
        SDL_Texture* texture_;
    };
};

#endif //GAME_IMAGE_H
