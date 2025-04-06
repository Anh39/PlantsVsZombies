// #include "engine.h"
// #include "Game/game.cpp"

// int main(int argc, char* argv[]) {
//     return StartGame();
// }

#include "engine.h"

class CustomBox: public ColorRect {
public:
    CustomBox() {};
    ~CustomBox() {};
    void Update(float delta) override {
        Rect rect = this->GetRect();
        Vector2 absolutePosition = this->GetAbsolutePosition();
        rect.x = absolutePosition.x;
        rect.y = absolutePosition.y;
        if (MouseEvent::JustPressed(MouseLeft) && rect.Contain(MouseEvent::Position())) {
            this->color = Color(0, 0, 255);
        }
    };
};

int main(int argc, char* argv[]) {
    // runExample();
    // run();
    Scene* scene = new Scene();
    scene->SetAsCurrentScene();
    Scene::window->SetSize(Vector2(700, 600));
    Scene::window->SetPosition(Vector2(50, 50));

    CustomBox* box = new CustomBox();
    box->size = Vector2(100, 100);
    box->position = Vector2(100, 100);
    box->color = Color(255, 0, 0);

    ColorRect* box2 = new ColorRect();
    box2->size = Vector2(100, 100);
    box2->position = Vector2(100, 100);
    box2->color = Color(0, 255, 0);

    scene->root->AddChildren(box);
    box->AddChildren(box2);

    GameLoop::Start();
    return 0;
}