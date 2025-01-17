#include "item.h"

Item::Item(){
    itemType = EMPTY;
    name = "EMPTY";
}

void Item::use() {}

void Item::setOwner(Player& owner) {
    this->owner = &owner;
}

std::string Item::getName() {
    return name;
}

bool Item::isUsable() {
    return true;
}
