#include "adrenaline.h"

Adrenaline::Adrenaline() {
    itemType = ADRENALINE;
    name = "Adrenaline";
}

void Adrenaline::use() {
    std::cout << owner->getName() << " used Adrenaline\n\n";
    Player* target = owner->getTarget();
    int itemCount = target->getItemCount();
    if (itemCount) {
        std::cout << "Select " << target->getName() << " item\nInput:";
        int index = getCorrectInt(0, itemCount - 1);
        Item* item = target->getItem()[index];
        item->setOwner(*owner);
        target->useItem(index);
        item->setOwner(*target);
    }
}
