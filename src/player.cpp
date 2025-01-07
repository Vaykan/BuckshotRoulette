#include "player.h"

#include <utility>

void Player::setHitPoint(int hitPoint) {
    this->hitPoint = hitPoint;
}

int Player::getHitPoint() const {
    return hitPoint;
}

void Player::changeHitPoint(int delta) {
    int newHitPoint = hitPoint + delta;
    if (newHitPoint > maxHitPoint) {
        newHitPoint = maxHitPoint;
    }else if (newHitPoint < 0) {
        newHitPoint = 0;
    }
    setHitPoint(newHitPoint);
}

void Player::setArrayItemSize(int size) {
    item.resize(size);
}

void Player::setMaxHitPoint(int maxHitPoint) {
    this->maxHitPoint = maxHitPoint;
}

int Player::getMaxHitPoint() const {
    return maxHitPoint;
}

void Player::setTarget(Player &target) {
    this->target = &target;
}

void Player::setShotgun(Shotgun &shotgun) {
    this->shotgun = &shotgun;
}

#include "items/pill.h"

void Player::addRandomItems(int count) {
    if (count > maxItem - item.size()) count = maxItem - item.size();

    for (int i = 0; i < count; ++i) {
        item.push_back(&itemStorage[rGetNum(0, itemStorage.size())]);
    }
}

void Player::setItemStorage(std::vector<Item> itemStorage) {
    this->itemStorage = std::move(itemStorage);
}

int Player::getItemCount() {
    return item.size();
}

void Player::useItem(int index) {
    item[index]->use();
}

void Player::getStats() {
    std::cout << name << ": \n"
    << "Hit Point: " << getHitPoint() << std::endl
    << "Items: " << item.size() << std::endl;
    for (int i = 0; i < item.size(); i++) {
        std::cout << i << ": " << item[i]->getName() << std::endl;
    }
}

void Player::setName(std::string name) {
    this->name = std::move(name);
}

std::string Player::getName() {
    return name;
}

Player *Player::getTarget() {
    return target;
}
