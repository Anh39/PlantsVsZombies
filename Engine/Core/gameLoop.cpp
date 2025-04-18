#include "gameLoop.h"
#include <SDL2/SDL.h>
#include "../event.h"
#include "scene.h"
using namespace std;

bool GameLoop::stopTime = false;
bool GameLoop::running = false;

void GameLoop::Pause() {
    GameLoop::stopTime = true;
}
void GameLoop::Resume() {
    GameLoop::stopTime = false;
}
bool GameLoop::IsPaused() {
    return GameLoop::stopTime;
}
void GameLoop::Start() {
    GameLoop::running = true;
    KeyboardEvent::Initialize();
    MouseEvent::Initialize();
    Scene::window->SetSize(Scene::window->GetSize());
    while (GameLoop::running)
    {
        float delayTime = 1000.0 / FPS;
        if (GameLoop::stopTime) {
            delayTime = 0;
        }
        KeyboardEvent::Update();
        MouseEvent::Update();
        Scene* currentScene = Scene::current;
        if (currentScene != nullptr) {
            currentScene->ProcessFrame(delayTime / 1000);
        }
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            return;
        } else if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_RESIZED) {
            Scene::window->SetSize(Vector2(e.window.data1, e.window.data2));
        }
        if (KeyboardEvent::JustPressed(KeyboardType::F2)) {
            vector<string> debugInfos = vector<string>();
            debugInfos.push_back("Scene : " + Scene::GetDebugInfo());
            debugInfos.push_back("Node : " + Node::GetDebugInfo());
            debugInfos.push_back("Texture : " + Texture::GetDebugInfo());
            cout << "-----Debug info-----" << endl;
            for (auto& line : debugInfos)
            {
                cout << line << endl;
            }
            cout << "--------End--------" << endl;   
        }
        SDL_Delay(int(delayTime));
    }
}

void GameLoop::Stop() {
    GameLoop::running = false;
    std::cout << "Exit game" << std::endl;
}