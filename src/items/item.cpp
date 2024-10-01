#include "items/item.h"
#include "random.h"
#include "player.h"


void Item::use(Player subject, Player object) {}

Item::Item() {
    itemType = EMPTY;
}

void Pill::use(Player subject, Player object) {

}
