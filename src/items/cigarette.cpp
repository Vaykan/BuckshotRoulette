#include "cigarette.h"

Cigarette::Cigarette() {
    name = "Cigarette";
    itemType = CIGARETTE;
}

void Cigarette::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Cigarette, restoring 1 HP\n\n");
    owner->changeHitPoint(1);
}