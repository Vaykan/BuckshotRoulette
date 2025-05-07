#include "saw.h"

Saw::Saw() {
    itemType = SAW;
    name = "Saw";
}

void Saw::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Saw\n\n");
    owner->getShotgun()->setDoubleDamage(true);
}