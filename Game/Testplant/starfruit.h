#pragma once

#include "engine.h"

#include "../level.h"

class TestPlant: public BasePlant
{
public:
    TestPlant() {
        this->sunCost = 200;
        this->size = Vector2(0, 0);
        this->textureRect = new TextureRect();
        this->textureRect->texture = GetIcon();
        this->AddChildren(this->textureRect);
    };
    ~TestPlant() {

    }

    BasePlant* Create() override {
        return new TestPlant();
    }
    void SetSize(const Vector2& size) override {
        this->size = size;
        this->textureRect->size = size;
    }
    Vector2 GetSize() override {
        return this->size;
    }
    Texture* GetIcon() override {
        return new Texture("asset/menu/Starfruit_body.png");
    }
private:
    Vector2 size;
    TextureRect* textureRect;
};