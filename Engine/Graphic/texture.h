#pragma once
#include "../dataTypes.h"
#include "wrapper.h"
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

class Texture 
{
public:
    SDL_Texture* sdlTexture;
    Texture(string filePath);

    static void setCurrentRenderer(Renderer* renderer);
private:
    static Renderer* currentRenderer;
};