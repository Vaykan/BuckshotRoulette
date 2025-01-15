//
// Created by admin on 15.01.2025.
//

#include "magnifier.h"

Magnifier::Magnifier() {
    itemType = MAGNIFIER;
    name = "Magnifier";
}

void Magnifier::use() {
    std::cout << owner->getName() << " used Magnifier\n\n";
    if (owner->getShotgun()->getBackShell() == LIVE)
        std::cout << "Current shell is LIVE\n\n";
    else
        std::cout << "Current shell is BLANK\n\n";
}
