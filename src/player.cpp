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
        item.push_back(itemStorage[rGetNum(0, itemStorage.size() - 1)]);
    }
}

void Player::setItemStorage(std::vector<Item*> itemStorage) {
    this->itemStorage = std::move(itemStorage);
}

int Player::getItemCount() {
    return item.size();
}

void Player::useItem(int index) {
    item[index]->use();
    item.erase(item.begin() + index);
}

void Player::getStats() {
    std::cout << name << ": \n"
    << "Hit Point: " << getHitPoint() << std::endl
    << "Item count: " << item.size() << std::endl;
    for (int i = 0; i < item.size(); i++) {
        std::cout << i << ": " << item[i]->getName() << std::endl;
    }
    std::cout << "\n\n";
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

std::vector<Item*> Player::getItemStorage() {
    return itemStorage;
}

Player::~Player() {
    for (auto & i : itemStorage) {
        delete i;
    }
}

bool Player::isSkipTurn() const {
    return skipTurn;
}

void Player::setSkipTurn(bool skipTurn, std::string reason) {
    this->skipTurn = skipTurn;
    reasonSkipTurn = reason;
}

std::string Player::getReasonSkipTurn() {
    return reasonSkipTurn;
}
