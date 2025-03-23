#pragma once
#include <SDL2/SDL_image.h>
#include "window.h"
#include "../dataTypes.h"

class Texture;
class Renderer 
{
public:
    SDL_Renderer* SDL();

    Renderer(Window* window);
    ~Renderer();

    void RenderRectangle(Rect rect, Color color);
    void RenderTexture(Rect rect, Texture* texture);
    void RenderTextureWithBackground(Rect rect, Texture* texture, Color color);
private:
    SDL_Renderer* sdlRenderer;
};