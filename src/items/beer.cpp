#include "beer.h"

Beer::Beer() {
    itemType = BEER;
    name = "Beer";
}

void Beer::use() {
    std::cout << owner->getName() << " used Beer\n\n";
    owner->getShotgun()->pumping();
}