#include "phone.h"

Phone::Phone() {
    itemType = PHONE;
    name = "Phone";
}

void Phone::use() {
    owner->getMyFrame()->getTextCtrl()->AppendText("\n");
    owner->getMyFrame()->getTextCtrl()->AppendText(owner->getName());
    owner->getMyFrame()->getTextCtrl()->AppendText(" used Phone");
    std::vector<ShellType>* magazine = &owner->getShotgun()->getMagazine();
    if (magazine->size() >= 2) {
        int index = rGetNum(0, magazine->size() - 1);
        if ((*magazine)[index] == LIVE) {
            owner->getMyFrame()->getTextCtrl()->AppendText("\nShell ");
            owner->getMyFrame()->getTextCtrl()->AppendText(std::to_string(-(index - magazine->size())));
            owner->getMyFrame()->getTextCtrl()->AppendText(" is LIVE");
        } else {
            owner->getMyFrame()->getTextCtrl()->AppendText("\nShell ");
            owner->getMyFrame()->getTextCtrl()->AppendText(std::to_string(-(index - magazine->size())));
            owner->getMyFrame()->getTextCtrl()->AppendText(" is BLANK");
        }
    } else {
        owner->getMyFrame()->getTextCtrl()->AppendText("\nHow Unfortunate...");
    }
}