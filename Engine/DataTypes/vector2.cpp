#include "vector2.h"
#include "math.h"

Vector2::Vector2(): x(0), y(0) {};
Vector2::Vector2(float x, float y): x(x), y(y) {};
SDL_Point Vector2::ToSDL() {
    SDL_Point point;
    point.x = round(this->x);
    point.y = round(this->y);
    return point;
}
// bool Vector2::operator=(const Vector2& other) const {
//     return this->x == other.x && this->y == other.y;
// }
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
float Vector2::GetLength() const {
    return sqrt(this->x * this->x + this->y * this->y);
}
float Vector2::GetSqrLength() const {
    return this->x * this->x + this->y * this->y;
}
Vector2::operator std::string() const {
    return "X:" + std::to_string(this->x) + " Y:" + std::to_string(this->y);
}
