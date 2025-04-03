#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../dataTypes.h"
#include "functional"


/// @class Window
/// @brief Wrapper class
class Window
{
public:
    Window(std::string title = "Window");
    ~Window();

    SDL_Window* SDL();

    /// @brief Get window title
    const std::string GetTitle();
    /// @brief Get window size
    const Vector2 GetSize();
    /// @brief Set window output size
    void SetSize(const Vector2& size);
    /// @brief Set window position
    void SetPosition(const Vector2& position);

    std::function<void(const Vector2&)> onResized;
private:
    std::string WindowTitle;
    Vector2 Size;

    SDL_Window* sdlWindow;
    SDL_Window* InitSDL();

};