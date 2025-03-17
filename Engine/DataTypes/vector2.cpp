#include "vector2.h"
#include "math.h"
#include <iostream>

Vector2::Vector2(): x(0), y(0) {};
Vector2::Vector2(Vector2F floatVector): x(round(floatVector.x)), y(round(floatVector.y)) {};
Vector2::Vector2(int x, int y): x(x), y(y) {};

Vector2F Vector2::ToFloat() {
    return Vector2F(this->x, this->y);
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(this->x + other.x, this->y + other.y);
}
Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(this->x - other.x, this->y - other.y); 
}
Vector2 Vector2::operator*(float scalar) const {
    return Vector2(this->x * scalar, this->y * scalar);
}
Vector2 Vector2::operator/(float scalar) const {
    if (scalar == 0) throw std::runtime_error("Division by zero");
    return Vector2(this->x / scalar, this->y / scalar);
}

Vector2& Vector2::operator+=(const Vector2& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}
Vector2& Vector2::operator-=(const Vector2& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}
Vector2& Vector2::operator*=(float scalar) {
    this->x = (float)this->x * scalar;
    this->y = (float)this->y * scalar;
    return *this;
}
Vector2& Vector2::operator/=(float scalar) {
    if (scalar == 0) throw std::runtime_error("Division by zero");
    this->x = (float)this->x / scalar;
    this->y = (float)this->y / scalar;
    return *this;
}