#include "loadingController.h"

LoadingController::LoadingController() {
    this->loading = false;
    this->time = 0;
    this->pseudJobTime = 10;
}
LoadingController::~LoadingController() {

}
void LoadingController::Start() {
    this->loading = true;
}
void LoadingController::Update(float delta) {
    if (!this->loading) {// && KeyboardEvent::JustReleased(KeyboardType::F5)) {
        this->loading = true;
        if (this->startFunction) {
            this->startFunction();
        }
    }
    if (this->loading) {
        this->time += delta;
        if (this->time > this->pseudJobTime) {
            this->loading = false;
            if (this->completeFunction) {
                this->completeFunction();
            }
        } else {
            float percent = this->time/delta;
            if (percent > 1) percent = 1;
            if (this->progressFuntion) {
                this->progressFuntion(this->time/this->pseudJobTime);
            }
        }
    }
}
void LoadingController::ProcessEvent(Event* event) {

}