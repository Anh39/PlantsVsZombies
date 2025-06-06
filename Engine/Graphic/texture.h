#pragma once
#include "../dataTypes.h"
#include <SDL2/SDL_image.h>
#include <iostream>

class Renderer;

/// @class Texture
/// @brief Wrapper class
class Texture 
{
public:
    static int instanceCount;

    /// @brief Create new texture with file path to image.
    Texture(std::string filePath);
    ~Texture();

    SDL_Texture* SDL();
    void SetTexture(SDL_Texture* texture, bool freeOld);
    /// @brief Get real image size.
    Vector2 GetImageSize();
    /// @brief Get class debug info
    static std::string GetDebugInfo() {
        return "Instance count " + std::to_string(Texture::instanceCount);
    }
private:
    SDL_Texture* sdlTexture = nullptr;
    static SDL_Texture* LoadTexture(const char* filePath);
};