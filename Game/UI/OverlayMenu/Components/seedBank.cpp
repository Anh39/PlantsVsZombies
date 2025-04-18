#include "seedBank.h"

SeedBank::SeedBank(int maxSlots) {
    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/SeedBank_P.png");
    this->background->position = Vector2(0, 0);

    this->AddChildren(this->background);
    this->maxSlots = maxSlots;
    this->cards = std::vector<PlantCard*>();
}

SeedBank::~SeedBank() {

}

void SeedBank::SetSize(const Vector2& size) {
    this->size = size;
    this->background->size = size;
}

void SeedBank::SetPlantSize(const Vector2& size) {
    for(PlantCard* card: this->cards) {
        card->SetPlantSize(size);
    }
    this->plantSize = size;
}

Vector2 SeedBank::GetPlantSize() {
    return this->plantSize;
}

void SeedBank::AddNewCard(BasePlant* templatePlant) {
    PlantCard* newCard = new PlantCard();
    float cardXSize = (this->size.x - 8 * (this->maxSlots-1)) / this->maxSlots;
    Vector2 cardSize = Vector2(cardXSize, this->size.y*0.9);
    newCard->SetSize(cardSize);
    newCard->position = Vector2(cardXSize * cards.size() , 0);
    newCard->SetTarget(templatePlant);
    newCard->SetPlantSize(this->plantSize);
    this->AddChildren(newCard);

    cards.push_back(newCard);
}