#include "engine.h"
#include "UI/mainUI.h"
#include "UI/plantCard.h"
#include "UI/map.h"
#include "Plants/peaShooter.h"
#include "Zombies/normalZombie.h"

int run() {
    Scene* scene = new Scene();
    UI* mainUI = new UI();
    scene->root->AddChildren(mainUI);

    Map* map = new Map();
    map->LoadMap("map.txt");
    map->position = Vector2(50, 150);
    map->SetSize(Vector2(720, 400));
    scene->root->AddChildren(map);

    Node* plants = new Node();
    scene->root->AddChildren(plants);
    Node* zombies = new Node();
    scene->root->AddChildren(zombies);

    PeaShooter* pea = new PeaShooter();
    pea->position = Vector2(0, 0);

    PlantCard* peaShooterCard = new PlantCard();
    peaShooterCard->SetTargetSize(Vector2(60, 60));
    peaShooterCard->SetTarget(pea);
    mainUI->topBar->AddChildren(peaShooterCard);


    NormalZombie* normalZombie = new NormalZombie();
    normalZombie->position = Vector2(500, 200);
    normalZombie->SetSize(Vector2(100, 100));
    zombies->AddChildren(normalZombie);

    scene->SetAsCurrentScene();
    GameLoop::Start();
    return 0;
}