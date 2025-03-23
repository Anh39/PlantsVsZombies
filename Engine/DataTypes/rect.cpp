#include "rect.h"

Rect::Rect(): x(0), y(0), w(-1), h(-1) {};
Rect::Rect(float x, float y): x(x), y(y), w(-1), h(-1) {};
Rect::Rect(float x, float y, float w, float h): x(x), y(y), w(w), h(h) {};
SDL_Rect Rect::ToSDL() {
    SDL_Rect rect;
    rect.x = round(this->x);
    rect.y = round(this->y);
    rect.w = round(this->w);
    rect.h = round(this->h);
    return rect;
}
Rect Rect::operator+(const Vector2& pos) const {
    return Rect(this->x + pos.x, this->y + pos.y, this->w, this->h);
}
Rect Rect::operator-(const Vector2& pos) const {
    return Rect(this->x - pos.x, this->y - pos.y, this->w, this->h);
}
Vector2 Rect::GetPosition() {
    return Vector2(this->x, this->y);
}
void Rect::SetPosition(const Vector2& pos) {
    this->x = pos.x;
    this->y = pos.y;
}
Vector2 Rect::GetSize() {
    return Vector2(this->x, this->y);
}
void Rect::SetSize(const Vector2& size) {
    this->w = size.x;
    this->h = size.y;
}
Rect::operator std::string() const {
    return "X:" + std::to_string(this->x) + " Y:" + std::to_string(this->y) + " W:" + std::to_string(this->w) + " H:" + std::to_string(this->h);
}
bool Rect::Intersect(const Rect& other) const {
    return !(this->x + this->w <= other.x || // left
             other.x + other.w <= this->x || // right
             this->y + this->h <= other.y || // up
             other.y + other.h <= this->y);  // down
}
bool Rect::Contain(const Vector2& pos) const {
    return pos.x >= this->x & pos.y >= this->y && pos.x <= this->x + this->w && pos.y <= this->y + this->h;
}