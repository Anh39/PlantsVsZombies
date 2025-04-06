#include "renderer.h"
#include "texture.h"


void LogErrorAndExitRenderer(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}
void renderTexture(Renderer* renderer, Texture* texture, Rect dest) {
    SDL_Rect sdlDest = dest.ToSDL();
    SDL_RenderCopy(renderer->SDL(), texture->SDL(), NULL, &sdlDest);
}
void renderTexture(Renderer* renderer, Texture* texture, Rect src, Rect dest) {
    SDL_Rect sdlDest = dest.ToSDL();
    SDL_Rect sdlSrc = src.ToSDL();
    SDL_RenderCopy(renderer->SDL(), texture->SDL(), &sdlSrc, &sdlDest);
}
void renderRectangle(Renderer* renderer, Rect dest, Color color) {
    SDL_Rect sdlDest = dest.ToSDL();
    SDL_SetRenderDrawColor(renderer->SDL(), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer->SDL(), &sdlDest);
}
void renderTexture(Renderer* renderer, Texture* texture, Rect dest, Color color) {
    SDL_Rect sdlDest = dest.ToSDL();
    SDL_SetRenderDrawColor(renderer->SDL(), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer->SDL(), &sdlDest);
    SDL_RenderCopy(renderer->SDL(), texture->SDL(), NULL, &sdlDest);
}

SDL_Renderer* CreateRenderer(Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window->SDL(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        LogErrorAndExitRenderer("CreateRenderer", SDL_GetError());
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, NAIVE_WIDTH, NAIVE_HEIGHT);
    return renderer;
}

Renderer::Renderer(Window* window) {
    this->sdlRenderer = CreateRenderer(window);
}
Renderer::~Renderer() {
    if (this->sdlRenderer) {
        SDL_DestroyRenderer(this->sdlRenderer);
        this->sdlRenderer = nullptr;
    }
}
SDL_Renderer* Renderer::SDL() {
    return this->sdlRenderer;
}

void Renderer::RenderTexture(Rect rect, Texture* texture) {
    if (texture != nullptr) {
        renderTexture(this, texture, rect);
    }
}
void Renderer::RenderTexture(Rect srcRect, Rect dstRect, Texture* texture) {
    if (texture != nullptr) {
        renderTexture(this, texture, srcRect, dstRect);
    }
}
void Renderer::RenderRectangle(Rect rect, Color color) {
    renderRectangle(this, rect, color);
}
void Renderer::RenderTextureWithBackground(Rect rect, Texture* texture, Color color) {
    if (texture != nullptr) {
        // if (rect.w == -1 || rect.h == -1) {
        //     Vector2 size = getImageSize(texture);
        //     rect.w = size.x;
        //     rect.h = size.y;
        // }
        renderTexture(this, texture, rect, color);
    }
}
