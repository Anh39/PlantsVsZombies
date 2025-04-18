#include "level.h"
using namespace std;


Level::Level() {
    this->plants = vector<BasePlant*>();
    this->zombies = vector<BaseZombie*>();
}

Level::~Level() {

}

BasePlant::BasePlant() {

}
BasePlant::~BasePlant() {

}

BasePlant* BasePlant::Create() {
    return new BasePlant();
}

void BasePlant::SetSize(const Vector2& size) {

}

Vector2 BasePlant::GetSize() {
    return Vector2(0, 0);
}

Texture* BasePlant::GetIcon() {
    return nullptr;
}