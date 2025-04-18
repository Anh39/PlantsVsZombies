#pragma once

#include "engine.h"
#include "menuButton.h"
#include <functional>

class OptionMenu: public Node
{
public:
    std::function<void()> OnBackToTitle;
    std::function<void()> OnBackToGame;

    OptionMenu(bool isTitle);
    ~OptionMenu();

    Vector2 GetSize();
};