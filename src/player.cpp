#include "player.h"

#include <utility>

Player::Player() {
    skipReason.reserve(2);
}

void Player::setHitPoint(int hitPoint) {
    this->hitPoint = hitPoint;
}

int Player::getHitPoint() const {
    return hitPoint;
}

void Player::changeHitPoint(int delta) {
    int newHitPoint = hitPoint + delta;
    if (newHitPoint <= 0) {
        newHitPoint = 0;
        dead = true;
    } else if (newHitPoint > maxHitPoint) {
        newHitPoint = maxHitPoint;
    }
    setHitPoint(newHitPoint);
}

void Player::setArrayItemSize(int size) {
    item.reserve(size);
}

void Player::setMaxHitPoint(int maxHitPoint) {
    this->maxHitPoint = maxHitPoint;
}

int Player::getMaxHitPoint() const {
    return maxHitPoint;
}

void Player::setTarget(Player& target) {
    this->target = &target;
}

void Player::setShotgun(Shotgun& shotgun) {
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
    if (item[index]->isUsable()) {
        item[index]->use();
        item.erase(item.begin() + index);
    } else {
        std::cout << "Cannot be used\n\n";
    }
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

Player* Player::getTarget() {
    return target;
}

std::vector<Item*>& Player::getItemStorage() {
    return itemStorage;
}

Player::~Player() {
    for (auto& i: itemStorage) {
        delete i;
    }
}

bool Player::isSkipTurn() const {
    return !skipReason.empty();
}

void Player::addSkipTurn(std::string reason) {
    skipReason.push_back(reason);
}

std::string Player::getReasonSkipTurn() {
    return skipReason.back();
}

Shotgun* Player::getShotgun() {
    return shotgun;
}

bool Player::isDead() {
    return dead;
}

std::vector<Item*>& Player::getItem() {
    return item;
}

bool Player::isHandcuffed() const {
    return IsHandcuffed;
}

void Player::setIsHandcuffed(bool isHandcuffed) {
    this->IsHandcuffed = isHandcuffed;
}

void Player::decreaseSkipTurn() {
    if (!skipReason.empty())
        skipReason.pop_back();
}