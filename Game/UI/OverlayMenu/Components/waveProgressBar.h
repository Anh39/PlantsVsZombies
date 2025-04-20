#pragma once

#include "engine.h"
#include "../../Widgets/include.h"
#include "../../../level.h"

class WaveProgressBar: public EventNode
{
public:
    WaveProgressBar(std::vector<ZombieWave> zombieWaves);
    ~WaveProgressBar();
    int GetNumWave();
    float GetProgress();
    Vector2 GetSize();
    void SetSize(const Vector2& size);
    
    void Update(float delta) override;
    void ProcessEvent(Event* event) override;
    void SetProgress(float progress);
    void SetTargetProgress(float progress);

private:

    void SetNumWave(int numWave);
    float step;
    float delayTime;
    float targetProgress;
    Vector2 size;
    int numWave;
    float progress;
    TextureRect* frontTextureRect;
    ProgressRect* backTextureRect;

    std::vector<TextureRect*> handlers;
    std::vector<TextureRect*> flags;
    TextureRect* zombieHead;

    std::vector<std::vector<int>> zombieCount;
    std::vector<std::vector<int>> currentProcess;
};