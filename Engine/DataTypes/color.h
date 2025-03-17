#pragma once
#include <SDL2/SDL_image.h>

struct Color 
{
public:
    int r;
    int g;
    int b;
    int a;
    Color();
    Color(int r, int g, int b);
    Color(int r, int g, int b, int a);

    SDL_Color ToSDL();

    bool operator==(const Color& other) const;
};