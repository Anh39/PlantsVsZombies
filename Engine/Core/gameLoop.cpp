#include "gameLoop.h"
#include <SDL2/SDL.h>
#include "../event.h"
#include "scene.h"

void GameLoop::Start() {
    KeyboardEvent::Initialize();
    MouseEvent::Initialize();
    while (true)
    {
        KeyboardEvent::Update();
        MouseEvent::Update();
        Scene* currentScene = Scene::current;
        if (currentScene != nullptr) {
            currentScene->Render();
        }
        SDL_Event e;
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_QUIT)) {
            return;
        }
        SDL_Delay(int(DELAY_TIME));
    }
}


