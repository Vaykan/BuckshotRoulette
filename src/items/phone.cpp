#include "phone.h"
#include "../aiManager.h"
#include "../shotgun.h"

Phone::Phone() {
    itemType = PHONE;
    name = "Phone";
}

void Phone::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Phone\n\n");
    std::vector<ShellType>* magazine = &owner->getShotgun()->getMagazine();
    if (magazine->size() >= 2) {
        int index = rGetNum(0, magazine->size() - 1);
        if ((*magazine)[index] == LIVE) {
            owner->getMyFrame()->getTextCtrl()->AppendText("Shell ");
            owner->getMyFrame()->getTextCtrl()->AppendText(std::to_string(-(index - magazine->size())));
            owner->getMyFrame()->getTextCtrl()->AppendText(" is LIVE\n\n");
            if (owner->getIsAI())
                owner->getAIManager().setMagazineType(AIShellTypeState::LIVE, index);
        } else {
            owner->getMyFrame()->getTextCtrl()->AppendText("Shell ");
            owner->getMyFrame()->getTextCtrl()->AppendText(std::to_string(-(index - magazine->size())));
            owner->getMyFrame()->getTextCtrl()->AppendText(" is BLANK\n\n");
            if (owner->getIsAI())
                owner->getAIManager().setMagazineType(AIShellTypeState::BLANK, index);
        }
    } else {
        owner->getMyFrame()->getTextCtrl()->AppendText("How Unfortunate...\n\n");
    }
}