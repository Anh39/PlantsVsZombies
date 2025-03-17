#include <SDL2/SDL.h>
#include <iostream>
#include "Engine/init.h"


class Player: public TextureRect 
{
public:
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
        if (MouseEvent::JustPressed(MouseType::MouseLeft)) {
            cout << "Mouse pressed " << MouseEvent::Position().x << "|" << MouseEvent::Position().y << endl;
        }
    }
};
class SpecialColorRect: public ColorRect 
{
public:
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
        }
    }
};


Scene* createUI() {
    Scene* scene = new Scene();
    scene->SetAsCurrentScene();

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
    playerChild->color = Color(255, 255, 0, 255);

    scene->root->AddChildren(redRect);
    redRect->AddChildren(greenRect);
    redRect->AddChildren(player);

    redRect->AddChildren(blueRect);
    player->AddChildren(playerChild);

    return scene;
}

int main(int argc, char* argv[]) {
    Scene* scene = createUI();
    GameLoop::Start();
    return 0;
}
// Todo
// Log scene tree