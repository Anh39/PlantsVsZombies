#include "rect.h"

Rect::Rect(): x(0), y(0), w(-1), h(-1) {};
Rect::Rect(float x, float y): x(x), y(y), w(-1), h(-1) {};
Rect::Rect(float x, float y, int w, int h): x(x), y(y), w(w), h(h) {};
SDL_Rect Rect::ToSDL() {
    SDL_Rect rect;
    rect.x = round(this->x);
    rect.y = round(this->y);
    rect.w = this->w;
    rect.h = this->h;
    return rect;
}

Rect Rect::operator+(const Vector2F& pos) const {
    return Rect(this->x + pos.x, this->y + pos.y, this->w, this->h);
}
Rect Rect::operator-(const Vector2F& pos) const {
    return Rect(this->x - pos.x, this->y - pos.y, this->w, this->h);
}

Vector2F Rect::GetPosition() {
    return Vector2F(this->x, this->y);
}
Rect Rect::copy() {
    return Rect(this->x, this->y, this->w, this->h);
}

Rect::operator std::string() const {
    return "x" + std::to_string(this->x) + " y" + std::to_string(this->y) + " w" + std::to_string(this->w) + " h" + std::to_string(this->h);
}
