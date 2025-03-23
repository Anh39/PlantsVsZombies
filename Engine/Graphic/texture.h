#pragma once
#include "../dataTypes.h"
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

class Renderer;
class Texture 
{
public:
    Texture(string filePath);
    ~Texture();
    SDL_Texture* SDL();
    Vector2 GetImageSize();
    static void SetCurrentRenderer(Renderer* renderer);
private:
    SDL_Texture* sdlTexture = nullptr;
    static Renderer* currentRenderer;
    static SDL_Texture* LoadTexture(const char* filePath);
};