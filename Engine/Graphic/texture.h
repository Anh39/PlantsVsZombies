#pragma once
#include "../dataTypes.h"
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

class Renderer;
class Texture 
{
public:
    static int instanceCount;

    Texture(string filePath);
    ~Texture();
    SDL_Texture* SDL();
    Vector2 GetImageSize();

    static string GetDebugInfo() {
        return "Instance count " + to_string(Texture::instanceCount);
    }
private:
    SDL_Texture* sdlTexture = nullptr;
    static SDL_Texture* LoadTexture(const char* filePath);
};