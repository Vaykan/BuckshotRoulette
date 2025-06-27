#include "magnifier.h"

Magnifier::Magnifier() {
    itemType = MAGNIFIER;
    name = "Magnifier";
}

void Magnifier::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Magnifier\n\n");
    if (owner->getShotgun()->getBackShell() == LIVE)
        owner->getMyFrame()->getTextCtrl()->AppendText("Current shell is LIVE\n\n");
    else
        owner->getMyFrame()->getTextCtrl()->AppendText("Current shell is BLANK\n\n");
}