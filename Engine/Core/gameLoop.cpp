#include "gameLoop.h"
#include <SDL2/SDL.h>
#include "../event.h"
#include "scene.h"

void GameLoop::Start() {
    KeyboardEvent::Initialize();
    MouseEvent::Initialize();
    while (true)
    {
        float delayTime = 1000.0 / FPS;
        KeyboardEvent::Update();
        MouseEvent::Update();
        Scene* currentScene = Scene::current;
        if (currentScene != nullptr) {
            currentScene->ProcessFrame(delayTime / 1000);
        }
        SDL_Event e;
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_QUIT)) {
            return;
        }
        SDL_Delay(int(delayTime));
    }
}


