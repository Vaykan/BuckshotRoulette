#include "magnifier.h"
#include "../aiManager.h"
#include "../shotgun.h"

Magnifier::Magnifier() {
    itemType = MAGNIFIER;
    name = "Magnifier";
}

void Magnifier::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Magnifier");
    if (owner->getShotgun()->getBackShell() == LIVE) {
        owner->getMyFrame()->getTextCtrl()->AppendText("\nCurrent shell is LIVE");
        if(owner->getIsAI())
            owner->getAIManager().setMagazineType(AIShellTypeState::LIVE, 0);
    }
    else {
        owner->getMyFrame()->getTextCtrl()->AppendText("\nCurrent shell is BLANK");
        if(owner->getIsAI())
            owner->getAIManager().setMagazineType(AIShellTypeState::BLANK, 0);
    }
}