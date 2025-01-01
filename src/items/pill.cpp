#include "pill.h"

Pill::Pill() {
    itemType = PILL;
}

void Pill::use(Player &subjectPlayer, Player &objectPlayer, Shotgun &shotgun) {
    bool isGoodLuck = rGetNum(0, 1);
    if(isGoodLuck) {
        subjectPlayer.changeHitPoint(2);
    }else {
        subjectPlayer.changeHitPoint(-1);
    }
}
