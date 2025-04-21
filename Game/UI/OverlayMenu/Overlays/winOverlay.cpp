#include "winOverlay.h"
#include "../../../level.h"

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
        this->Start();
    }
}
void WinOverlay::Start() {
    this->trophy->isVisible = true;
    this->trophy->Start();
}
void WinOverlay::ProcessEvent(Event* event) {
    WinEvent* winEvent = dynamic_cast<WinEvent*>(event);
    if (winEvent) {
        std::cout << "WIN" << std::endl;
        this->Start();
    }
}