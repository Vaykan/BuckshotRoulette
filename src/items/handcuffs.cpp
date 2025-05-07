#include "handcuffs.h"

Handcuffs::Handcuffs() {
    itemType = HANDCUFFS;
    name = "Handcuffs";
}

void Handcuffs::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" Skipped because Handcuffed\n\n");
    Player* target = owner->getTarget();
    target->addSkipTurn("Skipped because Handcuffed\n\n");
    target->setIsHandcuffed(true);
}

bool Handcuffs::isUsable() {
    Player* target = owner->getTarget();
    return !(target->isHandcuffed() || target->isSkipTurn());
}