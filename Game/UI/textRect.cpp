#include "textRect.h"
using namespace std;


TTF_Font* TextRect::font = nullptr;

TextRect::TextRect() {
    this->text = "";
    this->color = Color(255, 255, 255);
    this->texture = new Texture("");
}
TextRect::~TextRect() {

}
void TextRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    if (this->textChanged) {
        SDL_Surface* textSurface = TTF_RenderText_Blended(TextRect::font, this->text.c_str(), this->color.ToSDL());
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer->SDL(), textSurface);
        this->texture->SetTexture(textTexture, true);
        SDL_FreeSurface(textSurface);
        this->textChanged = false;
    }
    TextureRect::Draw(renderer, absolutePosition);
}
void TextRect::SetText(string text) 
{
    this->text = text;
    this->textChanged = true;
}
string TextRect::GetText() {
    return this->text;
}
