#include "cigarette.h"

Cigarette::Cigarette() {
    name = "Cigarette";
    itemType = CIGARETTE;
}

void Cigarette::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Cigarette, restoring 1 HP");
    int temp = owner->getHitPoint();
    owner->changeHitPoint(1);
    if (owner->getIsAI() && temp < owner->getHitPoint())
        owner->getAIManager().changeScore(1);
}