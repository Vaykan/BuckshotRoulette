#include "beer.h"

Beer::Beer() {
    itemType = BEER;
    name = "Beer";
}

void Beer::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Beer\n\nShell ejected: ");
    if (owner->getShotgun()->getBackShell() == LIVE)
        owner->getMyFrame()->getTextCtrl()->AppendText("LIVE\n\n");
    else
        owner->getMyFrame()->getTextCtrl()->AppendText("BLANK\n\n");
    owner->getShotgun()->pumping();
}