#ifndef BUCKSHOT_ROULETTE__ITEM_H
#define BUCKSHOT_ROULETTE__ITEM_H

#include "../enum.h"
#include "../player.h"
#include "../random.h"
#include "../input.h"

class Player;

class Item {
private:
protected:
    Item();
    std::string name;
    Player* owner{};
    ItemType itemType;
public:
    virtual void use();
    virtual bool isUsable();

    void setOwner(Player& owner);

    std::string getName();

    
};



#endif
