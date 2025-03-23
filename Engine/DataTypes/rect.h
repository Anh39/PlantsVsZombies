#pragma once
#include <SDL2/SDL_image.h>
#include "vector2.h"
#include <iostream>

/// @struct Rect
/// @brief Rectangle
struct Rect 
{
public:
    float x;
    float y;
    /// @brief Width 
    float w;
    /// @brief Height
    float h;
    Rect();
    Rect(float x, float y);
    Rect(float x, float y, float w, float h);

    /// @brief Convert to SDL_Rect
    SDL_Rect ToSDL();

    Rect operator+(const Vector2& pos) const;
    Rect operator-(const Vector2& pos) const;
    /// @brief Check if this Rect is intersect with other Rect
    bool Intersect(const Rect& other) const;
    /// @brief Check if this Rect contain a Vector2 (position)
    bool Contain(const Vector2& pos) const;

    /// @brief Get position of Rect
    Vector2 GetPosition();
    /// @brief Set position of Rect
    void SetPosition(const Vector2& pos);
    /// @brief Get size of Rect
    Vector2 GetSize();
    /// @brief Set size of Rect
    void SetSize(const Vector2& size);

    explicit operator std::string() const;
};