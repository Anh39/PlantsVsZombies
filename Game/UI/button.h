#pragma once
#include "engine.h"
#include <functional>

class TextureButton: public Node
{
public:
    std::function<void()> OnClicked;
    TextureRect* OnTextureRect;
    TextureRect* OffTextureRect;

    TextureButton();
    ~TextureButton();
    void Update(float delta) override;
    void SetSize(const Vector2& size);
};