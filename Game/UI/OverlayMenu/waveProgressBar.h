#pragma once

#include "engine.h"
#include "../Landing/progressRect.h"

class WaveProgressBar: public Node
{
public:
    WaveProgressBar();
    ~WaveProgressBar();
    int GetNumWave();
    void SetNumWave(int numWave);
    float GetProgress();
    void SetProgress(float progress);
    Vector2 GetSize();
    void SetSize(const Vector2& size);
    
    void Update(float delta) override;
private:
    Vector2 size;
    int numWave;
    float progress;
    TextureRect* frontTextureRect;
    ProgressRect* backTextureRect;

    std::vector<TextureRect*> handlers;
    std::vector<TextureRect*> flags;
    TextureRect* zombieHead;
};