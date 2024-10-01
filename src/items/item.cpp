#include "items/item.h"
#include "random.h"
#include "player.h"


void Item::use(Player &subjectPlayer, Player &objectPlayer) {}

Item::Item() {
    itemType = EMPTY;
}

