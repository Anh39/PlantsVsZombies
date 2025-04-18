#pragma once
#include "engine.h"
#include "../Widgets/include.h"
#include <functional>

class LoadBar: public Node
{
public:
    std::function<void()> startGameFunction;
    LoadBar();
    ~LoadBar();
    void Start();
    void Progress(float percent);
    void Stop();
    void Update(float delta) override;
private:
    bool loading;
    TextureRect* dirtPart;
    ProgressRect* grassPart;
    TextureRect* grassBall;
    TextRect* loadingTextRect;
    float textDelay;
    float textTime;
    int dotCount;
    int maxDotCount;
    std::string loadingText;

    Vector2 ballSize;
};