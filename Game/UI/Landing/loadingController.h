#pragma once
#include "engine.h"
#include <functional>

class LoadingController: public EventNode 
{
public:
    std::function<void()> startFunction;
    std::function<void(float)> progressFuntion;
    std::function<void()> completeFunction;
    LoadingController();
    ~LoadingController();

    void Start();
    void Update(float delta) override;
    void ProcessEvent(Event* event) override;
private:
    bool loading;

    float time;
    float pseudJobTime;
};