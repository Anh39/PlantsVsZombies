#pragma once
#include <SDL2/SDL_image.h>
#include "window.h"
#include "../dataTypes.h"

#define NAIVE_WIDTH 1920
#define NAIVE_HEIGHT 1080

class Texture;

/// @class Renderer
/// @brief Wrapper class that provide some basic functions
class Renderer 
{
public:
    /// @brief Get SDL_Renderer
    SDL_Renderer* SDL();

    Renderer(Window* window);
    ~Renderer();

    /// @brief Used to render a rectangle with color
    void RenderRectangle(Rect rect, Color color);
    /// @brief Used to render a texture without background
    void RenderTexture(Rect rect, Texture* texture);
    void RenderTexture(Rect srcRect, Rect dstRect, Texture* texture);
    void RenderTextureEx(Rect rect, Texture* texture, float angle);
    /// @brief Used to render a texture with background, not tested.
    void RenderTextureWithBackground(Rect rect, Texture* texture, Color color);
private:
    SDL_Renderer* sdlRenderer;
};