#include "engine.h"
#include "UI/mainUI.h"
#include "UI/plantCard.h"
#include "UI/map.h"
#include "Plants/peaShooter.h"
#include "Zombies/normalZombie.h"

Scene* SetupScene1();
Scene* SetupScene2();

class SceneSwitcher: public Node
{
public:
    void Update(float delat) override {
        if (KeyboardEvent::JustReleased(KeyboardType::F3)) {
            cout << "Switch to scene 1" << endl;
            delete Scene::current;
            Scene* scene = SetupScene1();
            scene->SetAsCurrentScene();
            throw runtime_error("Switch scene");
        }
        else if (KeyboardEvent::JustReleased(KeyboardType::F4)) {
            cout << "Switch to scene 2" << endl;
            delete Scene::current;
            Scene* scene = SetupScene2();
            scene->SetAsCurrentScene();
            throw runtime_error("Switch scene");
        }   
    }
};
Scene* SetupScene1() {
    Scene* scene = new Scene();
    SceneSwitcher* switcher = new SceneSwitcher();
    //UI
    UI* mainUI = new UI();
    scene->root->AddChildren(switcher);
    scene->root->AddChildren(mainUI);

    //Map
    Map* map = new Map();
    map->LoadMap("map.txt");
    map->position = Vector2(50, 150);
    map->SetSize(Vector2(1800, 800));
    scene->root->AddChildren(map);

    //Plant and zombie
    Node* plants = new Node();
    scene->root->AddChildren(plants);
    Node* zombies = new Node();
    scene->root->AddChildren(zombies);

    PeaShooter* pea = new PeaShooter();
    pea->position = Vector2(0, 0);

    // UI Card
    PlantCard* peaShooterCard = new PlantCard();
    peaShooterCard->SetTarget(pea);
    peaShooterCard->SetTargetSize(Vector2(60, 60));
    mainUI->topBar->AddChildren(peaShooterCard);

    // Zombie
    NormalZombie* normalZombie = new NormalZombie();
    normalZombie->position = Vector2(500, 200);
    normalZombie->SetSize(Vector2(100, 100));
    zombies->AddChildren(normalZombie);

    return scene;
}
Scene* SetupScene2() {
    Scene* scene = new Scene();
    SceneSwitcher* switcher = new SceneSwitcher();
    //UI
    scene->root->AddChildren(switcher);
    return scene;
}

int run() {
    Scene::window->SetSize(Vector2(1280, 720)); // Render size is 1920 * 1080, this is just window size
    Scene::window->SetPosition(Vector2(50, 50));

    Scene* scene1 = SetupScene1();
    scene1->SetAsCurrentScene();
    GameLoop::Start();
    return 0;
}