#pragma once
#include "engine.h"
#include "../textRect.h"

class LevelCard: public Node
{
public:
    std::function<void()> OnClicked;
    LevelCard();
    ~LevelCard();
    void Update(float delta) override;
    void SetSize(const Vector2& size);
    void SetText(std::string text);
    std::string GetText();
private:
    TextureRect* offBackground;
    TextureRect* onBackground;
    TextureRect* itemBackground;

    TextRect* levelText;
};