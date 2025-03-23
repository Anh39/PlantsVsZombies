#pragma once
#include "../dataTypes.h"
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

class Renderer;

/// @class Texture
/// @brief Wrapper class
class Texture 
{
public:
    static int instanceCount;

    /// @brief Create new texture with file path to image.
    Texture(string filePath);
    ~Texture();

    SDL_Texture* SDL();
    /// @brief Get real image size.
    Vector2 GetImageSize();
    /// @brief Get class debug info
    static string GetDebugInfo() {
        return "Instance count " + to_string(Texture::instanceCount);
    }
private:
    SDL_Texture* sdlTexture = nullptr;
    static SDL_Texture* LoadTexture(const char* filePath);
};