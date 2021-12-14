cmake_minimum_required(VERSION 3.20)
project(Game)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game src/main.cpp src/graphics/Image.cpp src/graphics/Image.h src/graphics/ImageManager.h src/Handle.h)

ExternalProject_Add(
        SDL2_External
        PREFIX "${CMAKE_SOURCE_DIR}/extern"
        URL "https://www.libsdl.org/release/SDL2-2.0.18-win32-x86.zip"
        # TODO -- hash here

)
