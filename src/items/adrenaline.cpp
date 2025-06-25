#include "adrenaline.h"

Adrenaline::Adrenaline() {
    itemType = ADRENALINE;
    name = "Adrenaline";
}

void Adrenaline::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Adrenaline\n\n");
    owner->setIsAdrenalineActive(true);
}

bool Adrenaline::isUsable() {
    return !owner->getIsAdrenalineActive();
}