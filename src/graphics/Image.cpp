/**
  * @file Image.cpp
*/

#include "Image.h"

using namespace graphics;

Image::Image(SDL_Texture& texture) noexcept : texture_(&texture) {};

auto Image::texture() const noexcept -> SDL_Texture*
{
        return texture_;
}