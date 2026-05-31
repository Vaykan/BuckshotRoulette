#include "pill.h"

Pill::Pill() {
    name = "Pill";
    itemType = PILL;
}

void Pill::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    int randBit = rGetRandBit();
    if (randBit) {
        owner->getMyFrame()->getTextCtrl()->AppendText(" used Pill, restoring 2 HP");
        owner->changeHitPoint(2);
    } else {
        owner->getMyFrame()->getTextCtrl()->AppendText(" used Pill, losing 1 HP");
        owner->changeHitPoint(-1);
    }
    if (owner->getIsAI()) {
        int delta = randBit ? 2 : -1;
        owner->getAIManager().changeScore(delta);
    }
}