#pragma once
#include "engine.h"
#include "SDL2/SDL_ttf.h"

class TextRect: public TextureRect
{
public:
    static TTF_Font* font;

    TextRect();
    ~TextRect();

    std::string GetText();
    void SetText(std::string text);
    void SetColor(const Color& color);
    Color GetColor();
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
private:
    Color color;
    bool textChanged;
    std::string text;
};