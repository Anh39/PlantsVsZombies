#pragma once

struct Vector2F 
{
public:
    float x;
    float y;
    Vector2F();
    Vector2F(float x, float y);

    Vector2F operator+(const Vector2F& other) const;
    Vector2F& operator+=(const Vector2F& other);
    Vector2F operator-(const Vector2F& other) const;
    Vector2F& operator-=(const Vector2F& other);
    Vector2F operator*(float scalar) const;
    Vector2F& operator*=(float scalar);
    Vector2F operator/(float scalar) const;
    Vector2F& operator/=(float scalar);
};