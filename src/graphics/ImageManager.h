/**
  * @file ImageManager.h
*/

#ifndef GAME_IMAGEMANAGER_H
#define GAME_IMAGEMANAGER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <optional>

#include "Image.h"
#include "../Handle.h"

namespace graphics
{
    class ImageManager
    {
        using Key = std::string;
        using Handle = utility::Handle<Image>;
        using Map = std::unordered_map<Key, Handle>;

    public:
        ImageManager() = delete;
        /// @brief Load image from file, and return a Handle to it
        auto loadImage(const char* path) -> std::optional<Image&>;
        /// @brief Borrow pointer `handle` represents for usage
        auto get_pointer(const Handle& handle) -> std::optional<Image&>;
        /// @brief Clear the cache and free the Image textures;
        void clear();

    private:
        Map cache;
        std::vector<Image> image_pool;
    };
}

#endif //GAME_IMAGEMANAGER_H
