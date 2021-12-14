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
        using Handle = utility::Handle;
        using Map = std::unordered_map<Key, Handle>;

    public:
        ImageManager() = delete;
        /// @brief Load image from file, and return a Handle to it
        std::optional<Handle> loadImage(const char* path);
        /// @brief Borrow pointer `handle` represents for usage
        std::optional<Image&> get_pointer(const Handle& handle);
        /// @brief Clear the cache and free the Image textures;
        void clear();

    private:
        Map cache;
        std::vector<Image>;
    };
}

#endif //GAME_IMAGEMANAGER_H
