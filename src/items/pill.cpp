#include "pill.h"

Pill::Pill() {
    name = "Pill";
    itemType = PILL;
}

void Pill::use() {
    if (rGetRandBit()) {
        owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
        owner->getMyFrame()->getTextCtrl()->AppendText(" used Pill, restoring 2 HP\n\n");
        owner->changeHitPoint(2);
    } else {
        owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
        owner->getMyFrame()->getTextCtrl()->AppendText(" used Pill, losing 1 HP\n\n");
        owner->changeHitPoint(-1);
    }
}