#include "magnifier.h"

Magnifier::Magnifier() {
    itemType = MAGNIFIER;
    name = "Magnifier";
}

void Magnifier::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Magnifier");
    if (owner->getShotgun()->getBackShell() == LIVE)
        owner->getMyFrame()->getTextCtrl()->AppendText("\nCurrent shell is LIVE");
    else
        owner->getMyFrame()->getTextCtrl()->AppendText("\nCurrent shell is BLANK");
}