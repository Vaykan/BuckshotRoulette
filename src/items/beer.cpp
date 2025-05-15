#include "beer.h"

Beer::Beer() {
    itemType = BEER;
    name = "Beer";
}

void Beer::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Beer\n\n");
    owner->getShotgun()->pumping();
}