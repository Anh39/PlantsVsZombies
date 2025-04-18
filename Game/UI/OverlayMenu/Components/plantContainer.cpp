#include "plantContainer.h"
#include "plantCard.h"

PlantContainer::PlantContainer() {
    this->Name = "PlantContainer";
}

PlantContainer::~PlantContainer() {

}

void PlantContainer::ProcessEvent(Event* event) {
    PlantCardPlacedEvent* plantCardPlacedEvent = dynamic_cast<PlantCardPlacedEvent*>(event);
    if (plantCardPlacedEvent) {
        plantCardPlacedEvent->handled = true;

        BasePlant* plant = plantCardPlacedEvent->plant;
        plant->SetParent(this);
        plant->position = plantCardPlacedEvent->absolutePosition - this->GetAbsolutePosition();
    }
}