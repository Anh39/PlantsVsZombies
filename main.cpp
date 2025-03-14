#include <SDL2/SDL.h>
#include <iostream>
#include "Engine/init.h"


class Player: public TextureRect 
{
public:
    float speed = 100;
    float runSpeedModifier = 2;
    void update(float delta) {
        float localSpeed = speed;
        if (KeyboardEvent::isPressed(KeyboardType::LShift)) {
            localSpeed *= runSpeedModifier;
        }
        if (KeyboardEvent::isPressed(KeyboardType::Right) || KeyboardEvent::isPressed(KeyboardType::D)) {
            this->rect.x += delta * localSpeed;
        }
        if (KeyboardEvent::isPressed(KeyboardType::Left) || KeyboardEvent::isPressed(KeyboardType::A)) {
            this->rect.x -= delta * localSpeed;
        }
        if (KeyboardEvent::isPressed(KeyboardType::Up) || KeyboardEvent::isPressed(KeyboardType::W)) {
            this->rect.y -= delta * localSpeed;
        }
        if (KeyboardEvent::isPressed(KeyboardType::Down) || KeyboardEvent::isPressed(KeyboardType::S)) {
            this->rect.y += delta * localSpeed;
        }
    }
};

Scene* createUI() {
    Scene* scene = new Scene();
    scene->setAsCurrentScene();

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

    ColorRect* playerChild = new ColorRect();
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
    KeyboardEvent::Initialize();
    Scene* scene = createUI();

    SDL_Event e;
    while (true)
    {
        KeyboardEvent::Update();
        scene->render();
        // cout << KeyboardEvent::isPressed(KeyboardType::Right);
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_QUIT)) {
            return 0;
        }
        SDL_Delay(int(DELAY_TIME));
    }

    return 0;
}
// Todo
// Log scene tree