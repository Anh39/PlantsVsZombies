#include "mainUI.h"

UI::UI() {
    this->Setup();
}
UI::~UI() {

}

void UI::Setup() {
    ColorRect* topBar = new ColorRect();
    topBar->rect = Rect(100, 0, 600, 60);
    topBar->color = Color(0, 255, 0);
    this->AddChildren(topBar);


}