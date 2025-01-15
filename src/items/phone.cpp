#include "phone.h"

Phone::Phone() {
    itemType = PHONE;
    name = "Phone";
}

void Phone::use() {
    std::cout << owner->getName() << " used Phone\n\n";
    std::vector<ShellType>* magazine =  &owner->getShotgun()->getMagazine();
    if (magazine->size() >= 2) {
        int index = rGetNum(1, magazine->size() - 1);
        if((*magazine)[index] == LIVE)
            std::cout << index + 1 << " shell LIVE\n\n";
        else
            std::cout << index + 1 << " shell BLANK\n\n";
    } else {
        std::cout << "How Unfortunate...\n\n";
    }
}
