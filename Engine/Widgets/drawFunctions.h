#pragma once
#include "../graphic.h"


void renderWithoutBackground(Renderer* renderer, Texture* texture, Rect rect);
void renderWithBackground(Renderer* renderer, Texture* texture, Rect rect, Color color);