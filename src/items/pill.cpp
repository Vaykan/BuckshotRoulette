#include "pill.h"

Pill::Pill() {
    name = "Pill";
    itemType = PILL;
}

void Pill::use() {
    if(rGetRandBit()){
        owner->changeHitPoint(2);
        std::cout << owner->getName() << " used Pill, restoring 2 HP\n";
    } else {
        owner->changeHitPoint(-1);
        std::cout << owner->getName() << " used Pill, losing 1 HP\n";
    }
}

