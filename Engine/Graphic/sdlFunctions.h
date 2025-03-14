#pragma once

#include <vector>
#include <SDL2/SDL_image.h>
#include "wrapper.h"
#include "texture.h"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define WINDOW_TITLE "HELLO" 

void logErrorAndExit(const char* msg, const char* error);
void waitUntilKeyPressed();
SDL_Window* initSDL();
SDL_Renderer* createRenderer(SDL_Window* window);
void renderTexture(Renderer* renderer, Texture* texture, Rect dest);
void renderTexture(Renderer* renderer, Texture* texture, Rect dest, Color color);
void renderRectangle(Renderer* renderer, Rect dest, Color color);
Vector2 getImageSize(Texture* texture);