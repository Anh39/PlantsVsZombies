#pragma once
#include <SDL2/SDL_image.h>

class Renderer 
{
public:
    SDL_Renderer* sdlRenderer;

    Renderer();
};

class Window
{
public:
    SDL_Window* sdlWindow;

    Window();
};