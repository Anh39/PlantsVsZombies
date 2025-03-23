#include "color.h"

Color::Color(): r(0), g(0), b(0), a(255) {};
Color::Color(unsigned char r, unsigned char g, unsigned char b): r(r), g(g), b(b), a(255) {};
Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a): r(r), g(g), b(b), a(a) {};

SDL_Color Color::ToSDL() {
    SDL_Color color;
    color.r = this->r;
    color.g = this->g;
    color.b = this->b;
    color.a = this->a;
    return color;
}

bool Color::operator==(const Color& other) const {
    return this->r == other.r && this->g == other.g && this->b == other.b && this->a == other.a;
}