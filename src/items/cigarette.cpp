#include "cigarette.h"

Cigarette::Cigarette() {
    name = "Cigarette";
    itemType = CIGARETTE;
}

void Cigarette::use() {
    owner->changeHitPoint(1);
    std::cout << owner->getName() << " used Cigarette, restoring 1 HP\n";
}
