#pragma once
#include <SDL2/SDL_image.h>

/// @struct Color
/// @brief Represent RGBA Color. Range from 0->255
struct Color 
{
public:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    /// @brief Convert to SDL_Color
    SDL_Color ToSDL();
    bool operator==(const Color& other) const;
};