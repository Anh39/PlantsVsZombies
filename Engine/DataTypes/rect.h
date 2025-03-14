#pragma once
#include <SDL2/SDL_image.h>
#include "vector2f.h"
#include <iostream>

struct Rect 
{
public:
    float x;
    float y;
    int w;
    int h;
    Rect();
    Rect(float x, float y);
    Rect(float x, float y, int w, int h);

    SDL_Rect toSDL();
    Rect operator+(const Vector2F& pos) const;
    Rect operator-(const Vector2F& pos) const;

    Vector2F getPosition();
    Rect copy();

    explicit operator std::string() const;
};