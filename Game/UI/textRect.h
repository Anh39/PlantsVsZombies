#pragma once
#include "engine.h"
#include "SDL2/SDL_ttf.h"

class TextRect: public TextureRect
{
public:
    static TTF_Font* font;

    TextRect();
    ~TextRect();
    Color color;

    std::string GetText();
    void SetText(std::string text);
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
private:
    bool textChanged;
    std::string text;
};