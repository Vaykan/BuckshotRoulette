#include "saw.h"

Saw::Saw() {
    itemType = SAW;
    name = "Saw";
}

void Saw::use() {
    std::cout << owner->getName() << " used Saw\n\n";
    owner->getShotgun()->setDoubleDamage(true);
}
