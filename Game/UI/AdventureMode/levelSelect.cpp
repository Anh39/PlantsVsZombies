#include "levelSelect.h"

using namespace std;

LevelSelectMenu::LevelSelectMenu(Vector2 gridSize) {
    this->gridSize = gridSize;
    this->cards = vector<vector<LevelCard*>>();
    int count = 0;
    for(int y=0; y<this->gridSize.y; y++) {
        vector<LevelCard*> row = vector<LevelCard*>();
        for(int x=0; x<this->gridSize.x; x++) {
            count++;
            LevelCard* newCard = new LevelCard();
            newCard->SetText(to_string(count));
            row.push_back(newCard);
            this->AddChildren(newCard);
        }
        this->cards.push_back(row);
    }
}
void LevelSelectMenu::SetSize(const Vector2& size) {
    this->size = size;
    this->Refresh();
}
void LevelSelectMenu::SetSpacing(const Vector2& spacing) {
    this->spacing = spacing;
    this->Refresh();
}
void LevelSelectMenu::Refresh() {
    Vector2 itemSize = Vector2(
        (this->size.x-(this->gridSize.x-1)*spacing.x) / this->gridSize.x,
        (this->size.y-(this->gridSize.y-1)*spacing.y) / this->gridSize.y
    );
    for(int y=0; y<this->gridSize.y; y++) {
        for(int x=0; x<this->gridSize.x; x++) {
            LevelCard* card = this->cards[y][x];
            card->SetSize(itemSize);
            card->position = Vector2(
                x*(itemSize.x + spacing.x),
                y*(itemSize.y + spacing.y)
            );
        }
    }
}
LevelSelectMenu::~LevelSelectMenu() {

}