#include "sunBank.h"

// SunBank* SunBank::current = nullptr;
// float SunBank::GetAmount() {
//     if (SunBank::current != nullptr) {
//         return SunBank::current->Amount;
//     }
//     return 0;
// }

SunBank::SunBank() {
    this->Amount = 0;

    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/SunBank.png");

    this->counter = new TextRect();
    this->counter->SetColor(Color(0, 0, 0));

    this->AddChildren(this->background);
    this->AddChildren(this->counter);
    // SunBank::current = this;
}

SunBank::~SunBank() {

}

void SunBank::Update(float delta) {
    Vector2 size = this->background->size;
    if (this->Amount >= 1000) { // 4
        this->counter->position.x = size.x*0.2;
        this->counter->size.x = size.x*0.6;
    } 
    else if (this->Amount >= 100) { // 3
        this->counter->position.x = size.x*0.35;
        this->counter->size.x = size.x*0.45;
    }
    else if (this->Amount >= 10) { // 2
        this->counter->position.x = size.x*0.5;
        this->counter->size.x =size.x*0.3;
    }
    else { // 1
        this->counter->position.x = size.x*0.65;
        this->counter->size.x = size.x*0.15;
    }
    this->counter->SetText(std::to_string(int(this->Amount)));

}

void SunBank::SetSize(const Vector2& size) {
    this->background->size = size;
    this->counter->position = Vector2(size.x*0.2, size.y*0.7);
    this->counter->size = Vector2(size.x*0.6, size.y*0.2);
}

void SunBank::ProcessEvent(Event* event) {
    SunCollectedEvent* sunCollectedEvent = dynamic_cast<SunCollectedEvent*>(event);
    if (sunCollectedEvent) {
        this->Amount += sunCollectedEvent->amount;
    }
    SunSpentEvent* sunSpentEvent = dynamic_cast<SunSpentEvent*>(event);
    if (sunSpentEvent) {
        this->Amount -= sunSpentEvent->amount;
    }
}