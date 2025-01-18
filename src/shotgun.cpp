#include "shotgun.h"

void Shotgun::shoot(Player* target) {
    std::cout << "\n\n";
    if (magazine.back() == LIVE) {
        std::cout << "SHOT!\n";
        if (doubleDamage)
            target->changeHitPoint(-2);
        else
            target->changeHitPoint(-1);
    } else {
        std::cout << "CLICK!\n";
    }
    pumping();
    doubleDamage = false;
}

void Shotgun::pumping() {
    if (magazine.back() == LIVE)
        std::cout << "LIVE shell ejected\n";
    else
        std::cout << "BLANK shell ejected\n";
    magazine.pop_back();
    std::cout << "\n\n";
}

void Shotgun::loading(int count) {
    for (int i = 0; i < count; ++i) {
        magazine.push_back(BLANK);
    }
    int liveLeft = count / 2;
    while (liveLeft) {
        int i = rGetNum(0, magazine.size() - 1);
        if (magazine[i] == BLANK) {
            magazine[i] = LIVE;
            liveLeft--;
        }
    }
}

bool Shotgun::isEmpty() {
    return magazine.empty();
}

void Shotgun::setSizeMagazine(int size) {
    magazine.reserve(size);
}

void Shotgun::displayMagazineContents() {
    int live = 0;
    int blank = 0;
    for (auto& i: magazine) {
        if (i == LIVE)
            live++;
        else
            blank++;
    }
    std::cout << "Shotgun loaded:\n"
              << live << " Live\n"
              << blank << " Blank\n\n";
}

ShellType& Shotgun::getBackShell() {
    return magazine.back();
}

std::vector<ShellType>& Shotgun::getMagazine() {
    return magazine;
}

bool Shotgun::isDoubleDamage() const {
    return doubleDamage;
}

void Shotgun::setDoubleDamage(bool doubleDamage) {
    this->doubleDamage = doubleDamage;
}