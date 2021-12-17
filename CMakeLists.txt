cmake_minimum_required(VERSION 3.20)
project(Game)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game src/main.cpp src/graphics/Image.cpp src/graphics/Image.h src/graphics/ImageManager.h src/Handle.h src/graphics/Texture.cpp src/graphics/Texture.h src/graphics/Window.cpp src/graphics/Window.h)

set_target_properties(
        Game
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

ExternalProject_Add(
        SDL2
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/extern/SDL2"
        URL "https://www.libsdl.org/release/SDL2-devel-2.0.18-VC.zip"
        # TODO -- hash here
        # Ensure no configuration or building happens, just pure download
        CONFIGURE_COMMAND  ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
        LOG_INSTALL ON
)

add_dependencies(Game SDL2)
target_include_directories(
        Game
        PRIVATE
        "${CMAKE_SOURCE_DIR}/extern/SDL2/include"
)
# include appropriate libraries
# *only* works on x86!!

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(INFO "Using 64-bit build.")
    set(Game_SDL2_lib_path "${CMAKE_SOURCE_DIR}/extern/SDL2/lib/x64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(INFO "Using 32-bit build.")
    set(Game_SDL2_lib_path "${CMAKE_SOURCE_DIR}/extern/SDL2/lib/x86")
endif()

target_link_libraries(
        Game
        PRIVATE
        "${Game_SDL2_lib_path}/SDL2.lib"
        "${Game_SDL2_lib_path}/SDL2main.lib"
)

# copy
add_custom_command(TARGET Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${Game_SDL2_lib_path}/SDL2.dll"          # <--this is in-file
        "${CMAKE_SOURCE_DIR}/bin")                # <--this is out-file path