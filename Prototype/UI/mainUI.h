#pragma once
#include "engine.h"

class UI: public Node {
public:
    UI();
    ~UI();

    ColorRect* topBar;

    const string GetClassName() override {return "UI";}
    
private:
    void Setup();
};