#ifndef BUCKSHOT_ROULETTE_PLAYER_H
#define BUCKSHOT_ROULETTE_PLAYER_H

#include <vector>

#include "items/item.h"
#include "shotgun.h"
#include "enum.h"

class Item;


class Player {
private:
    std::string name;
    int hitPoint = 0;
    int maxHitPoint = 0;
    int maxItem = 8;
    std::vector<Item*> item;
    std::vector<Item> itemStorage;
    Shotgun* shotgun;
    Player* target;

public:
    void changeHitPoint(int delta);

    void addRandomItems(int count);
    int getItemCount();
    void useItem(int index);

    void setTarget(Player& target);
    void setShotgun(Shotgun& shotgun);
    void setItemStorage(std::vector<Item> itemStorage);
    void setHitPoint(int hitPoint);
    void setMaxHitPoint(int maxHitPoint);
    void setArrayItemSize(int size);
    void setName(std::string name);

    void getStats();
    int getMaxHitPoint() const;
    int getHitPoint() const;
    std::string getName();
    Player* getTarget();


};

#endif
