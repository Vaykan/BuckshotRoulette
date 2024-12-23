#ifndef BUCKSHOT_ROULETTE_PLAYER_H
#define BUCKSHOT_ROULETTE_PLAYER_H

#include <vector>

#include "items/item.h."
#include "shotgun.h"
#include "enum.h"

class Item;


class Player {
private:
    int hitPoint = 0;
    int maxHitPoint = 0;
    int maxItem = 8;
    std::vector<ItemType> item;
    std::vector<Item> itemStorage;
    Shotgun* shotgun;
    Player* target;

public:
    void changeHitPoint(int delta);
    void addRandomItem(int count);

    void setTarget(Player& target);
    void setShotgun(Shotgun& shotgun);
    void setItemStorage(std::vector<Item> itemStorage);
    void setHitPoint(int hitPoint);
    void setMaxHitPoint(int maxHitPoint);
    void setArrayItemSize(int size);


    int getMaxHitPoint() const;
    int getHitPoint() const;


};

#endif
