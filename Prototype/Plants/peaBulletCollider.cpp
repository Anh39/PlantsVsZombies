#include "peaBulletCollider.h"
#include <iostream>
using namespace std;
PeaBulletCollider::PeaBulletCollider() {
    this->Name = "PeaBulletCollider";
}
PeaBulletCollider::~PeaBulletCollider() {

}
void PeaBulletCollider::OnCollide(CollideNode* other) {
    cout << "Collided" << endl;
    other->parent->Delete();
    this->parent->Delete();
}