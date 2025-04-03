#include "normalZombie.h"
using namespace std;

NormalZombie::NormalZombie() {
    this->Name = "NormalZombie";

    this->colorRect->color = Color(255, 0, 0);
}
NormalZombie::~NormalZombie() {

}
BaseZombie* NormalZombie::Copy() {
    return nullptr;
}

void NormalZombie::Update(float delta) {
    this->position += Vector2(-10, 0) * delta;
    // CollideNode* collideRect = static_cast<CollideNode*>(this->GetChild("CollideNode"));
    // cout << string(collideRect->GetRect()) << endl;
}
