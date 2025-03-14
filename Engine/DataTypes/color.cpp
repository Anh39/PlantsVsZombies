#include "color.h"

Color::Color(): r(0), g(0), b(0), a(255) {};
Color::Color(int r, int g, int b): r(r), g(g), b(b), a(255) {};
Color::Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a) {};

SDL_Color Color::toSDL() {
    SDL_Color color;
    color.r = this->r;
    color.g = this->g;
    color.b = this->b;
    color.a = this->a;
    return color;
}

