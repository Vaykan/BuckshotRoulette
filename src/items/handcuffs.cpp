#include "handcuffs.h"

Handcuffs::Handcuffs() {
    itemType = HANDCUFFS;
    name = "Handcuffs";
}

void Handcuffs::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Handcuffs");
    Player* target = owner->getTarget();
    target->addSkipTurn("\n" + target->getName() + " Skipped because Handcuffed");
    target->setIsHandcuffed(true);
}

bool Handcuffs::isUsable() {
    Player* target = owner->getTarget();
    return !(target->isHandcuffed() || target->isSkipTurn());
}