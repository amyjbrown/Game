/**
  * @file Handle.h
  * @brief
  * @author Amy Brown 
*/

#ifndef GAME_HANDLE_H
#define GAME_HANDLE_H

#include <cstddef>

namespace utility {
    /// @brief A handle into some resource, use this instead of pointers
    template <typename T>
    struct Handle
    {
        std::size_t index;
    };
}

#endif //GAME_HANDLE_H
