#include "inverter.h"

Inverter::Inverter() {
    itemType = INVERTER;
    name = "Inverter";
}

void Inverter::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Inverter\n\n");
    ShellType* currentShell = &owner->getShotgun()->getBackShell();
    if (*currentShell == LIVE)
        *currentShell = BLANK;
    else
        *currentShell = LIVE;
}