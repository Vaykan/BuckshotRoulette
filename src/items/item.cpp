#include "item.h"

Item::Item(){
    itemType = EMPTY;
}

void Item::use() {}

void Item::setOwner(Player& owner) {
    this->owner = &owner;
}

void Item::setTarget(Player& target) {
    this->target = &target;
}
