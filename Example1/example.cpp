#include <SDL2/SDL.h>
#include <iostream>
#include "../Engine/init.h"

Scene* CreateScene1();
Scene* CreateScene2();

class Bullet : public ColorRect
{
public:
    const char* className = "Bullet";

    Vector2 velocity;
    void Update(float delta) {
        this->rect = this->rect + velocity * delta;
    }
    Bullet() {
        this->velocity = Vector2(0, 0);
    }
    void OnCollide(Node* other) override {
        this->parent->RemoveChildren(this);
        this->Delete();
        this->Delete();

    }
    const string GetClassName() { return "Bullet"; }

};

class Player: public TextureRect 
{
public:
    const char* className = "Player";

    float speed = 100;
    float runSpeedModifier = 2;
    void Update(float delta) {
        float localSpeed = speed;
        if (KeyboardEvent::IsPressing(KeyboardType::LShift)) {
            localSpeed *= runSpeedModifier;
        }
        if (KeyboardEvent::IsPressing(KeyboardType::Right) || KeyboardEvent::IsPressing(KeyboardType::D)) {
            this->rect.x += delta * localSpeed;
        }
        if (KeyboardEvent::IsPressing(KeyboardType::Left) || KeyboardEvent::IsPressing(KeyboardType::A)) {
            this->rect.x -= delta * localSpeed;
        }
        if (KeyboardEvent::IsPressing(KeyboardType::Up) || KeyboardEvent::IsPressing(KeyboardType::W)) {
            this->rect.y -= delta * localSpeed;
        }
        if (KeyboardEvent::IsPressing(KeyboardType::Down) || KeyboardEvent::IsPressing(KeyboardType::S)) {
            this->rect.y += delta * localSpeed;
        }
        if (MouseEvent::JustPressed(MouseType::MouseLeft)  && this->rect.Contain(MouseEvent::Position())) {
            cout << "Mouse pressed " << MouseEvent::Position().x << "|" << MouseEvent::Position().y << endl;
        }

        if (KeyboardEvent::JustPressed(KeyboardType::Space)) {
            cout << "Spawn" << endl;
            spawn();
        }

        if (KeyboardEvent::JustReleased(KeyboardType::F3)) {
            cout << "Switch to scene 2" << endl;
            delete Scene::current;
            Scene* scene = CreateScene2();
            scene->SetAsCurrentScene();
            throw runtime_error("Switch scene");
        }
        if (KeyboardEvent::JustReleased(KeyboardType::F4)) {
            cout << "Switch to scene 1" << endl;
            delete Scene::current;
            Scene* scene = CreateScene1();
            scene->SetAsCurrentScene();
            throw runtime_error("Switch scene");
        }   
    }
    void spawn() {
        Bullet* bullet = new Bullet();
        bullet->velocity = Vector2(20, 0);
        bullet->rect = Rect(0, 0, 50, 50);
        bullet->color = Color(255, 255, 255);
        bullet->collideMask = 1;
        this->AddChildren(bullet);
    }
    const string GetClassName() { return "Player"; }

    string Info() {
        return "Player Id " + string(this->id) + "|" + string(this->rect);
    }
};
class Target: public ColorRect 
{
public:
    const char* className = "Target";
    void OnCollided(Node* other) override {
        cout << other->GetClassName() << "|" << this->GetClassName() << endl;
        Bullet* bullet = dynamic_cast<Bullet*>(other);
        if (bullet) {
            cout << bullet->GetClassName() << " collide with " << this->GetClassName() << endl;
        } else {
            cout << "Failed to cast" << endl;
        }
    }
    const string GetClassName() { return "Target"; }
};
class SpecialColorRect: public ColorRect 
{
public:
    const char* className = "SpecialColorRect";

    void Update(float delta) {
        Color red = Color(255, 0, 0, 255);
        Color green = Color(0, 255, 0, 255);
        Color blue = Color(0, 0, 255, 255);
        if (MouseEvent::JustPressed(MouseType::MouseLeft)) {
            if (this->color == red) {
                this->color = green;
            } else if (this-> color == green) {
                this->color = blue;
            } else {
                this->color = red;
            }
            cout << this->className << endl;
        }
    }
    const string GetClassName() { return "SpecialColorRect"; }
 
};


Scene* CreateScene1() {
    Scene* scene = new Scene();

    ColorRect* redRect = new ColorRect();
    redRect->rect = Rect(0, 0, 100, 100);
    redRect->color = Color(255, 0, 0, 255);

    ColorRect* greenRect = new ColorRect();
    greenRect->rect = Rect(50, 50, 100, 100);
    greenRect->color = Color(0, 255, 0, 255);

    ColorRect* blueRect = new ColorRect();
    blueRect->rect = Rect(100, 100, 100, 100);
    blueRect->color = Color(0, 0, 255, 255);

    Player* player = new Player();
    player->rect = Rect(50, 60, 100, 100);
    player->texture = new Texture("images/Spongebob.png");

    ColorRect* playerChild = new SpecialColorRect();
    playerChild->rect = Rect(50, 50, 50, 50);
    playerChild->color = Color(255, 255, 0);



    Target* target = new Target();
    target->rect = Rect(500, 0, 100, 100);
    target->color = Color(255, 0, 0);
    target->collideFilter = 1;

    scene->root->AddChildren(redRect);
    redRect->AddChildren(greenRect);
    redRect->AddChildren(player);

    redRect->AddChildren(blueRect);
    player->AddChildren(playerChild);
    redRect->AddChildren(target);

    return scene;
}

Scene* CreateScene2() {
    Scene* scene = new Scene();


    Player* player = new Player();
    player->rect = Rect(50, 60, 100, 100);
    player->texture = new Texture("images/Spongebob.png");

    ColorRect* playerChild = new SpecialColorRect();
    playerChild->rect = Rect(50, 50, 50, 50);
    playerChild->color = Color(255, 255, 0);



    Target* target = new Target();
    target->rect = Rect(500, 0, 100, 100);
    target->color = Color(255, 0, 0);
    target->collideFilter = 1;

    scene->root->AddChildren(player);

    player->AddChildren(playerChild);
    scene->root->AddChildren(target);

    return scene;
}
int runExample() {
    Scene* scene = CreateScene1();
    scene->SetAsCurrentScene();
    GameLoop::Start();
    return 0;
}