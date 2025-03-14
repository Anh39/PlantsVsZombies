#include "sdlFunctions.h"
#include <iostream>

void logErrorAndExit(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true)
    {
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) {
            return;
        }
        SDL_Delay(100);
    }
}

SDL_Texture* loadTextureX(const char* filePath, SDL_Renderer* renderer) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filePath);
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (texture == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
    }
    return texture;
}

SDL_Window* initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logErrorAndExit("SDL_init", SDL_GetError());
    }
    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        logErrorAndExit("Create window", SDL_GetError());
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        logErrorAndExit("SDL_image error", SDL_GetError());
    }
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        logErrorAndExit("CreateRenderer", SDL_GetError());
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    return renderer;
}

void renderTexture(Renderer* renderer, Texture* texture, Rect dest) {
    SDL_Rect sdlDest = dest.toSDL();
    SDL_RenderCopy(renderer->sdlRenderer, texture->sdlTexture, NULL, &sdlDest);
}
void renderRectangle(Renderer* renderer, Rect dest, Color color) {
    SDL_Rect sdlDest = dest.toSDL();
    SDL_SetRenderDrawColor(renderer->sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer->sdlRenderer, &sdlDest);
}
void renderTexture(Renderer* renderer, Texture* texture, Rect dest, Color color) {
    SDL_Rect sdlDest = dest.toSDL();
    SDL_SetRenderDrawColor(renderer->sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer->sdlRenderer, &sdlDest);
    SDL_RenderCopy(renderer->sdlRenderer, texture->sdlTexture, NULL, &sdlDest);
}
Vector2 getImageSize(Texture* texture) {
    int w, h;
    SDL_QueryTexture(texture->sdlTexture, nullptr, nullptr, &w, &h);
    Vector2 result = Vector2();
    result.x = w;
    result.y = h;
    return result;
}