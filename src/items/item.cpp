#include "items/item.h"

Item::Item(Player& owner, Player& target){
    itemType = EMPTY;
    this->owner = &owner;
    this->target = &target;
}

void Item::use() {}

void Item::setOwner(Player& owner) {
    this->owner = &owner;
}

void Item::setTarget(Player& target) {
    this->target = &target;
}
