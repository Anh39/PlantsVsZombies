#pragma once
#include "../graphic.h"


void RenderWithoutBackground(Renderer* renderer, Texture* texture, Rect rect);
void RenderWithBackground(Renderer* renderer, Texture* texture, Rect rect, Color color);