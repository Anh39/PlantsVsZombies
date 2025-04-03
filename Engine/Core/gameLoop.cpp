#include "gameLoop.h"
#include <SDL2/SDL.h>
#include "../event.h"
#include "scene.h"
using namespace std;
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


