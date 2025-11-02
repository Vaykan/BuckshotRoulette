#include "beer.h"

Beer::Beer() {
    itemType = BEER;
    name = "Beer";
}

void Beer::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Beer");
    owner->getShotgun()->pumping();
}