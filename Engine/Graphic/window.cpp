#include "window.h"
using namespace std;
#include "../Core/scene.h"
#include "SDL2/SDL_ttf.h"
void LogErrorAndExitWindow(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* Window::InitSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 || TTF_Init() < 0) {
        LogErrorAndExitWindow("SDL_init", SDL_GetError());
    }
    SDL_Window* window = SDL_CreateWindow(
        this->WindowTitle.c_str(), 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        NAIVE_WIDTH, 
        NAIVE_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (window == nullptr) {
        LogErrorAndExitWindow("Create window", SDL_GetError());
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        LogErrorAndExitWindow("SDL_image error", SDL_GetError());
    }
    return window;
}

Window::Window(string title) {
    this->WindowTitle = title;
    this->sdlWindow = InitSDL();
}
Window::~Window() {
    if (this->sdlWindow) {
        SDL_DestroyWindow(this->sdlWindow);
        this->sdlWindow = nullptr;
    }
}
void Window::SetSize(const Vector2& size) {
    float aspectRatio = float(NAIVE_WIDTH)/float(NAIVE_HEIGHT);
    Vector2 newSize = size;
    if (size.x / size.y > aspectRatio) {
        newSize.y = size.x/aspectRatio;
    } else {
        newSize.x = size.y*aspectRatio;
    }
    this->Size = newSize;
    SDL_SetWindowSize(this->sdlWindow, int(newSize.x), int(newSize.y));
    if (this->onResized) {
        this->onResized(newSize);
    }
}
void Window::SetPosition(const Vector2& position) {
    SDL_SetWindowPosition(this->sdlWindow, int(position.x), int(position.y));
}
SDL_Window* Window::SDL() {
    return this->sdlWindow;
}

const string Window::GetTitle() {
    return this->WindowTitle;
}
const Vector2 Window::GetSize() {
    return this->Size;
}