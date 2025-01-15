#include "handcuffs.h"

Handcuffs::Handcuffs() {
    itemType = HANDCUFFS;
    name = "Handcuffs";
}

void Handcuffs::use() {
    owner->getTarget()->setSkipTurn(1, "Skipped because ");
}
