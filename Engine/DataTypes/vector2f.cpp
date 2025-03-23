// #include "vector2f.h"
// #include <iostream>
// #include <math.h>

// Vector2F::Vector2F(): x(0.0f), y(0.0f) {};
// Vector2F::Vector2F(float x, float y): x(x), y(y) {};

// // Vector2F::Vector2F(Vector2 intVector): x(intVector.x), y(intVector.y) {};

// // Vector2 Vector2F::toInt() {
// //     return Vector2(round(this->x), round(this->y));
// // }

// Vector2F Vector2F::operator+(const Vector2F& other) const {
//     return Vector2F(this->x + other.x, this->y + other.y);
// }
// Vector2F Vector2F::operator-(const Vector2F& other) const {
//     return Vector2F(this->x - other.x, this->y - other.y); 
// }
// Vector2F Vector2F::operator*(float scalar) const {
//     return Vector2F(this->x * scalar, this->y * scalar);
// }
// Vector2F Vector2F::operator/(float scalar) const {
//     if (scalar == 0) throw std::runtime_error("Division by zero");
//     return Vector2F(this->x / scalar, this->y / scalar);
// }

// Vector2F& Vector2F::operator+=(const Vector2F& other) {
//     this->x += other.x;
//     this->y += other.y;
//     return *this;
// }
// Vector2F& Vector2F::operator-=(const Vector2F& other) {
//     this->x -= other.x;
//     this->y -= other.y;
//     return *this;
// }
// Vector2F& Vector2F::operator*=(float scalar) {
//     this->x *= scalar;
//     this->y *= scalar;
//     return *this;
// }
// Vector2F& Vector2F::operator/=(float scalar) {
//     if (scalar == 0) throw std::runtime_error("Division by zero");
//     this->x /= scalar;
//     this->y /scalar;
//     return *this;
// }