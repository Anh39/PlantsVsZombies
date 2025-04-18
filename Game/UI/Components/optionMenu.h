#pragma once

#include "engine.h"
#include "menuButton.h"
#include <functional>

class OptionMenu: public Node
{
public:
    std::function<void()> OnBackToGame;

    OptionMenu();
    ~OptionMenu();

    Vector2 GetSize();
};