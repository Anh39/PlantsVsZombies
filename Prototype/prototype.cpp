#include "engine.h"
#include "UI/mainUI.h"
#include "Plants/peaShooter.h"

int run() {
    Scene* scene = new Scene();
    UI* mainUI = new UI();
    scene->root->AddChildren(mainUI);

    Node* plants = new Node();
    scene->root->AddChildren(plants);

    PeaShooter* pea = new PeaShooter();
    pea->rect.SetPosition(Vector2(100, 100));
    plants->AddChildren(pea);

    scene->SetAsCurrentScene();
    GameLoop::Start();
    return 0;
}