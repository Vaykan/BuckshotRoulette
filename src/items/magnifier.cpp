#include "magnifier.h"
#include "../aiManager.h"
#include "../shotgun.h"

Magnifier::Magnifier() {
    itemType = MAGNIFIER;
    name = "Magnifier";
}

void Magnifier::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Magnifier\n\n");
    if (owner->getShotgun()->getBackShell() == LIVE) {
        owner->getMyFrame()->getTextCtrl()->AppendText("Current shell is LIVE\n\n");
        if(owner->getIsAI())
            owner->getAIManager().setShellType(AIShellTypeState::LIVE, 0);
    }
    else {
        owner->getMyFrame()->getTextCtrl()->AppendText("Current shell is BLANK\n\n");
        if(owner->getIsAI())
            owner->getAIManager().setShellType(AIShellTypeState::BLANK, 0);
    }
}