#include "window.h"

void LogErrorAndExitWindow(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* Window::InitSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LogErrorAndExitWindow("SDL_init", SDL_GetError());
    }
    SDL_Window* window = SDL_CreateWindow(
        this->WindowTitle.c_str(), 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        int(this->Size.x), 
        int(this->Size.y),
        SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        LogErrorAndExitWindow("Create window", SDL_GetError());
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        LogErrorAndExitWindow("SDL_image error", SDL_GetError());
    }
    return window;
}

Window::Window(string title, Vector2 size) {
    this->WindowTitle = title;
    this->Size = size;
    this->sdlWindow = InitSDL();
}
Window::~Window() {
    if (this->sdlWindow) {
        SDL_DestroyWindow(this->sdlWindow);
        this->sdlWindow = nullptr;
    }
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