#include "texture.h"
using namespace std;

Renderer* Texture::currentRenderer = nullptr;

SDL_Texture* loadTexture(const char* filePath, Renderer* renderer) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filePath);
    SDL_Texture* texture = IMG_LoadTexture(renderer->sdlRenderer, filePath);
    if (texture == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
    }
    return texture;
}
Texture::Texture(string filePath = "") {
    if (filePath == "") {
        sdlTexture = nullptr;
    } else {
        sdlTexture = loadTexture(filePath.c_str(), Texture::currentRenderer);
    }
}
void Texture::setCurrentRenderer(Renderer* renderer) {
    Texture::currentRenderer = renderer;
}