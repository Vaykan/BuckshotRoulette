#include "phone.h"

Phone::Phone() {
    itemType = PHONE;
    name = "Phone";
}

void Phone::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Phone\n\n");
    std::vector<ShellType>* magazine = &owner->getShotgun()->getMagazine();
    if (magazine->size() >= 2) {
        int index = rGetNum(1, magazine->size() - 1);
        if ((*magazine)[index] == LIVE) {
            owner->getMyFrame()->getTextCtrl()->AppendText(std::to_string(index + 1));
            owner->getMyFrame()->getTextCtrl()->AppendText(" shell LIVE\n\n");
        } else {
            owner->getMyFrame()->getTextCtrl()->AppendText(std::to_string(index + 1));
            owner->getMyFrame()->getTextCtrl()->AppendText(" shell BLANK\n\n");
        }
    } else {
        owner->getMyFrame()->getTextCtrl()->AppendText("How Unfortunate...\n\n");
    }
}