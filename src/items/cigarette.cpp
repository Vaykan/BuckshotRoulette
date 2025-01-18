#include "cigarette.h"

Cigarette::Cigarette() {
    name = "Cigarette";
    itemType = CIGARETTE;
}

void Cigarette::use() {
    std::cout << owner->getName() << " used Cigarette, restoring 1 HP\n\n";
    owner->changeHitPoint(1);
}