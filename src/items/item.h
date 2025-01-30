#ifndef BUCKSHOT_ROULETTE_ITEM_H
#define BUCKSHOT_ROULETTE_ITEM_H

#include "../enum.h"
#include "../player.h"
#include "../random.h"
#include "../input.h"

class Player;

class Item {
protected:
    Item();

    std::string name;
    ItemType itemType;

    Player* owner{};
public:
    std::string getName();
    ItemType getItemType();

    void setOwner(Player& owner);

    virtual void use();
    virtual bool isUsable();
};

#endif