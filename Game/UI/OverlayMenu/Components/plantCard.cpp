#include "plantCard.h"
#include "sunController.h"

PlantCard::PlantCard() {
    this->isMoving = false;
    this->targetPlant = nullptr;
    this->createdTarget = nullptr;
    this->cardSize = Vector2(0, 0);
    this->plantSize = Vector2(0, 0);
    this->time = 0;

    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/SeedPacket_Larger.png");

    this->AddChildren(this->background);

    this->iconRect = new TextureRect();
    this->AddChildren(this->iconRect);

    this->sunCostTextRect = new TextRect();
    this->sunCostTextRect->SetColor(Color(0, 0, 0));
    this->AddChildren(this->sunCostTextRect);

    this->cooldownOverlay = new ColorRect();
    this->cooldownOverlay->color = Color(0, 0, 0, 127);
    this->AddChildren(this->cooldownOverlay);

    this->suncostOverlay = new ColorRect();
    this->suncostOverlay->color = Color(0, 0, 0, 127);
    this->AddChildren(this->suncostOverlay);
}

PlantCard::~PlantCard() {

}
void PlantCard::Update(float delta) {
    if (this->targetPlant != nullptr) {
        this->time -= delta;
        float percent = this->time / this->targetPlant->cardCooldown;
        if (percent < 0) percent = 0;
        if (percent > 1) percent = 1;
        this->cooldownOverlay->size.y = this->iconRect->size.y*percent;
        this->cooldownOverlay->position.y = this->iconRect->size.y*(1-percent) + this->iconRect->position.y;

        Vector2 mousePosition = MouseEvent::Position();
        Rect rect = this->GetRect();
        rect.SetPosition(this->GetAbsolutePosition());
        if (this->time < 0 && !this->suncostOverlay->isVisible && this->isMoving == false && MouseEvent::JustPressed(MouseType::MouseLeft) && rect.Contain(mousePosition)) {
            this->isMoving = true;
            this->createdTarget = this->CreateTarget();
            this->createdTarget->isVisible = true;
            this->createdTarget->SetSize(this->plantSize);
            this->AddChildren(this->createdTarget); // Tempory add to this
        }
        if (this->isMoving) {
            this->createdTarget->position = mousePosition - this->GetAbsolutePosition() - this->createdTarget->GetSize() / 2;
            Vector2 absolutePosition = mousePosition - this->createdTarget->GetSize() / 2;
            PlantCardHoverEvent* hoverEvent = new PlantCardHoverEvent(this->iconRect->texture, absolutePosition);
            EventQueue::PushEvent(hoverEvent);
    
            if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
                PlantCardPlacedEvent* placeEvent = new PlantCardPlacedEvent(this->createdTarget, absolutePosition);
                EventQueue::PushEvent(placeEvent);
                placeEvent->onSuccess = [this]() {
                    this->time = this->targetPlant->cardCooldown;
                    SunSpentEvent* sunEvent = new SunSpentEvent(this->targetPlant->sunCost);
                    EventQueue::PushEvent(sunEvent);
                };
                this->isMoving = false;
                this->createdTarget = nullptr;
            }
        }
    }
}
void PlantCard::SetTarget(BasePlant* target) {
    this->iconRect->texture = target->GetIcon();

    this->targetPlant = target;
    this->AddChildren(this->targetPlant);
    this->targetPlant->isVisible = false;
    this->time = this->targetPlant->cardCooldown;

    this->RefreshSunCost();
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
    this->cooldownOverlay->position = this->iconRect->position;
    this->cooldownOverlay->size = this->iconRect->size;
    this->suncostOverlay->position = this->iconRect->position;
    this->suncostOverlay->size = this->iconRect->size;
    this->sunCostTextRect->position = Vector2(0, size.y * 0.8);
    this->sunCostTextRect->size = Vector2(0, size.y * 0.15);
    this->RefreshSunCost();
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

void PlantCard::UpdateSunCostOverlay(float sunAmount) {
    this->suncostOverlay->isVisible = true;
    if (this->targetPlant != nullptr) {
        if (this->targetPlant->sunCost <= sunAmount) {
            this->suncostOverlay->isVisible = false;
        }
    }
}

void PlantCard::RefreshSunCost() {
    if (this->targetPlant != nullptr) {
        float offset = 0.1;
        if (this->targetPlant->sunCost >= 100) {
            this->sunCostTextRect->position.x = this->cardSize.x*(0.35-offset);
            this->sunCostTextRect->size.x = this->cardSize.x*0.45;
        }
        else if (this->targetPlant->sunCost >= 10) {
            this->sunCostTextRect->position.x = this->cardSize.x*(0.5-offset);
            this->sunCostTextRect->size.x = this->cardSize.x*0.3;
        }
        else {
            this->sunCostTextRect->position.x = this->cardSize.x*(0.65-offset);
            this->sunCostTextRect->size.x = this->cardSize.x*0.15;
        }
        this->sunCostTextRect->SetText(std::to_string(int(this->targetPlant->sunCost)));
    }
}