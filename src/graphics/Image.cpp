/**
  * @file Image.cpp
*/

#include "Image.h"

using namespace graphics;

Image::Image(SDL_Texture& texture) noexcept
{
  texture_ = &texture;
  int w = 0,
      h = 0;
  // Get the actual dimensions of a texture if we couldn't actually load it.
  SDL_QueryTexture(
          texture_,
          nullptr,
          nullptr,
          &w,
          &h
          );
  clip = SDL_Rect {0,0,w,h};
};

Image::Image(SDL_Texture& texture, SDL_Rect clip) noexcept
    : texture_(&texture),
      clip() {};

auto Image::texture() const noexcept -> SDL_Texture*
{
        return texture_;
}