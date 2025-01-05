#include "shotgun.h"

void Shotgun::shoot(Player *target) {
    if (magazine.back() == LIVE) {
        std::cout << "SHOT!\n";
        target->changeHitPoint(-1);
    } else {
        std::cout << "CLICK!\n";
    }
    pumping();
}

void Shotgun::pumping() {
    if(magazine.back() == LIVE)
        std::cout << "LIVE shell ejected\n";
    else
        std::cout << "BLANK shell ejected\n";
    magazine.pop_back();
}

void Shotgun::loading(int count) {
    int liveLeft = count / 2;
    while (liveLeft) {
        int i = rGetNum(0, count - 1);
        if(magazine[i] == BLANK){
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