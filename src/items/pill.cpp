#include "pill.h"

Pill::Pill() {
    name = "Pill";
    itemType = PILL;
}

void Pill::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    if (rGetRandBit()) {
        owner->getMyFrame()->getTextCtrl()->AppendText(" used Pill, restoring 2 HP");
        owner->changeHitPoint(2);
    } else {
        owner->getMyFrame()->getTextCtrl()->AppendText(" used Pill, losing 1 HP");
        owner->changeHitPoint(-1);
    }
}