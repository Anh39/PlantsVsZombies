#pragma once
#include "engine.h"
#include "levelCard.h"
#include <vector>

class LevelSelectMenu: public Node
{
public:
    std::vector<std::vector<LevelCard*>> cards;
    LevelSelectMenu(Vector2 gridSize);
    ~LevelSelectMenu();

    void SetSize(const Vector2& size);
    void SetSpacing(const Vector2& spacing);
private:
    Vector2 size;
    Vector2 gridSize;
    Vector2 spacing;
    void Refresh();
};