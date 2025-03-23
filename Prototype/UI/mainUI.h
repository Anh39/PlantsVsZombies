#pragma once
#include "engine.h"

class UI: public Node {
public:
    UI();
    ~UI();

    const string GetClassName() override {return "UI";}
    
private:
    void Setup();
};