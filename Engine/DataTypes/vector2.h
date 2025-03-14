#pragma once
#include "vector2f.h"


struct Vector2 
{
public:
    int x;
    int y;
    Vector2();
    Vector2(Vector2F floatVector);
    Vector2(int x, int y);
    Vector2F toFloat();

    Vector2 operator+(const Vector2& other) const;
    Vector2& operator+=(const Vector2& other);
    Vector2 operator-(const Vector2& other) const;
    Vector2& operator-=(const Vector2& other);
    Vector2 operator*(float scalar) const;
    Vector2& operator*=(float scalar);
    Vector2 operator/(float scalar) const;
    Vector2& operator/=(float scalar);
};