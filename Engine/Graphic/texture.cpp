#include "texture.h"
#include "renderer.h"
using namespace std;

Renderer* Texture::currentRenderer = nullptr;

SDL_Texture* Texture::LoadTexture(const char* filePath) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filePath);
    SDL_Texture* texture = IMG_LoadTexture(Texture::currentRenderer->SDL(), filePath);
    if (texture == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());
    }
    return texture;
}
Texture::Texture(string filePath = "") {
    if (filePath == "") {
        sdlTexture = nullptr;
    } else {
        sdlTexture = this->LoadTexture(filePath.c_str());
    }
}
Texture::~Texture() {
    if (this->sdlTexture) {
        SDL_DestroyTexture(this->sdlTexture);
        this->sdlTexture = nullptr;
    }
}
SDL_Texture* Texture::SDL() {
    return this->sdlTexture;
}
void Texture::SetCurrentRenderer(Renderer* renderer) {
    Texture::currentRenderer = renderer;
}
Vector2 Texture::GetImageSize() {
    int w, h;
    SDL_QueryTexture(this->sdlTexture, nullptr, nullptr, &w, &h);
    Vector2 result = Vector2();
    result.x = w;
    result.y = h;
    return result;
}