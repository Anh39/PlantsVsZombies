#pragma once
#include <SDL2/SDL_image.h>
#include <math.h>
#include <iostream>

/// @struct Vector2
/// @brief Struct to hold info like Position, Size
struct Vector2 
{
public:
    float x;
    float y;
    Vector2();
    Vector2(float x, float y);
    /// @brief Convert to SDL_Point
    SDL_Point ToSDL();

    Vector2 operator+(const Vector2& other) const;
    Vector2& operator+=(const Vector2& other);
    Vector2 operator-(const Vector2& other) const;
    Vector2& operator-=(const Vector2& other);
    Vector2 operator*(float scalar) const;
    Vector2& operator*=(float scalar);
    Vector2 operator/(float scalar) const;
    Vector2& operator/=(float scalar);

    /// @brief Get length of Vector
    float GetLength() const;
    /// @brief Get squarred length of Vector 
    float GetSqrLength() const;

    explicit operator std::string() const;
};