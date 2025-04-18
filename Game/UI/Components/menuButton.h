#pragma once

#include "engine.h"
#include <functional>
#include "../Widgets/include.h"

class MenuButton: public Node 
{
public:
    std::function<void()> OnClicked;

    MenuButton();
    ~MenuButton();

    void SetSize(const Vector2& size);
    void SetText(std::string text);
    void SetColor(const Color& color);

    void Update(float delta) override;
private:
    TextureRect* leftTexture;
    TextureRect* middleTexture;
    TextureRect* rightTexture;

    TextRect* textRect;

    Vector2 size;
    Color color;
};