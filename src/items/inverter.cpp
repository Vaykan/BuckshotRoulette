#include "inverter.h"

Inverter::Inverter() {
    itemType = INVERTER;
    name = "Inverter";
}

void Inverter::use() {
    std::cout << owner->getName() << " used Inverter\n\n";
    ShellType* currentShell = &owner->getShotgun()->getBackShell();
    if (*currentShell == LIVE)
        *currentShell = BLANK;
    else
        *currentShell = LIVE;
}
