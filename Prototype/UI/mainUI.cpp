#include "mainUI.h"

UI::UI() {
    this->Name = "MainUI";
    this->Setup();
}
UI::~UI() {
    this->topBar->Delete();
}

void UI::Setup() {
    this->topBar = new ColorRect();
    topBar->position = Vector2(100, 0);
    topBar->size = Vector2(600, 60);
    topBar->color = Color(0, 127, 127);
    this->AddChildren(topBar);
}