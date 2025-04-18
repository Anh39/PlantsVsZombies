#include "winOverlay.h"

WinOverlay::WinOverlay() {
    this->trophy = new Trophy();
    this->AddChildren(this->trophy);
    this->trophy->isVisible = false;
    this->trophy->OnEnd = [this]() {
        this->trophy->isVisible = false;
        if (this->OnEnd) {
            this->OnEnd();
        }
    };
}

WinOverlay::~WinOverlay() {
    
}

void WinOverlay::Update(float delta) {
    if (KeyboardEvent::JustPressed(KeyboardType::F7)) {
        this->trophy->isVisible = true;
        this->trophy->Start();
    }
}