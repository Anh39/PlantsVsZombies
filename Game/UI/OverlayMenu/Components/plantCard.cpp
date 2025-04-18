#include "plantCard.h"

PlantCard::PlantCard() {
    this->isMoving = false;
    this->targetPlant = nullptr;
    this->createdTarget = nullptr;
    this->cardSize = Vector2(0, 0);
    this->plantSize = Vector2(0, 0);

    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/SeedPacket_Larger.png");

    this->AddChildren(this->background);

    this->iconRect = new TextureRect();
    this->AddChildren(this->iconRect);
}

PlantCard::~PlantCard() {

}
void PlantCard::Update(float delta) {
    Vector2 mousePosition = MouseEvent::Position();
    Rect rect = this->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (this->isMoving == false && MouseEvent::JustPressed(MouseType::MouseLeft) && rect.Contain(mousePosition)) {
        std::cout << "START" << std::endl;
        this->isMoving = true;
        this->createdTarget = this->CreateTarget();
        this->createdTarget->isVisible = true;
        this->createdTarget->SetSize(this->plantSize);
        this->AddChildren(this->createdTarget); // Tempory add to this
    }
    if (this->isMoving) {
        this->createdTarget->position = mousePosition - this->GetAbsolutePosition() - this->createdTarget->GetSize() / 2;
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            Vector2 absolutePosition = mousePosition - this->createdTarget->GetSize() / 2;
            PlantCardPlacedEvent* event = new PlantCardPlacedEvent(this->createdTarget, absolutePosition);
            EventQueue::PushEvent(event);

            this->isMoving = false;
            this->createdTarget = nullptr;
        }
    }
}
void PlantCard::SetTarget(BasePlant* target) {
    this->iconRect->texture = target->GetIcon();

    this->targetPlant = target;
    this->AddChildren(this->targetPlant);
    this->targetPlant->isVisible = false;
}

BasePlant* PlantCard::CreateTarget() {
    if (this->targetPlant != nullptr) {
        return this->targetPlant->Create();
    } else {
        return nullptr;
    }
}

void PlantCard::SetSize(const Vector2& size) {
    this->cardSize = size;
    this->background->size = size;
    this->iconRect->position = Vector2(size.x * 0.1, size.y * 0.125);
    this->iconRect->size = Vector2(size.x * 0.8, size.y * 0.6);
}

Vector2 PlantCard::GetSize() {
    return this->cardSize;
}
void PlantCard::SetPlantSize(const Vector2& size) {
    this->plantSize = size;

}
Vector2 PlantCard::GetPlantSize() {
    return this->plantSize;
}
Rect PlantCard::GetRect() {
    return Rect(this->position.x, this->position.y, this->cardSize.x, this->cardSize.y);
}
