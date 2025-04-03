#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../dataTypes.h"

/// @class Window
/// @brief Wrapper class
class Window
{
public:
    Window(std::string title = "Window", Vector2 size = {800, 600});
    ~Window();

    SDL_Window* SDL();

    /// @brief Get window title
    const std::string GetTitle();
    /// @brief Get window size
    const Vector2 GetSize();
private:
    std::string WindowTitle;
    Vector2 Size;

    SDL_Window* sdlWindow;
    SDL_Window* InitSDL();

};