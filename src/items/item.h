#ifndef BUCKSHOT_ROULETTE__ITEM_H
#define BUCKSHOT_ROULETTE__ITEM_H

#include "../enum.h"
#include "../player.h"
#include "../random.h"

class Player;

class Item {
private:
protected:
    Item();
    std::string name;
    Player* owner;
    ItemType itemType;
public:
    virtual void use();

    virtual void setOwner(Player& owner);

    virtual std::string getName();

    
};



#endif
