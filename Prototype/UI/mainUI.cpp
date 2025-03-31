#include "mainUI.h"

UI::UI() {
    this->Setup();
}
UI::~UI() {
    this->topBar->Delete();
}

void UI::Setup() {
    this->topBar = new ColorRect();
    topBar->rect = Rect(100, 0, 600, 60);
    topBar->color = Color(0, 127, 127);
    this->AddChildren(topBar);


}