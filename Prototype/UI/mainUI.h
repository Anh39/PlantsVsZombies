#pragma once
#include "engine.h"

class UI: public Node {
public:
    UI();
    ~UI();

    ColorRect* topBar;
    
private:
    void Setup();
};