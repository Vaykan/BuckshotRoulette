#include "session.h"



void Session::config() {
    dealer.setTarget(player);
    dealer.setShotgun(shotgun);
    dealer.setItemStorage({Pill(), Cigarette()});

    player.setTarget(dealer);
    player.setShotgun(shotgun);
    player.setItemStorage({Pill(), Cigarette()});
}

void Session::start() {
    Player* object;
    Player* subject;

    object = &dealer;
    subject = &player;

    while (player.getHitPoint() && dealer.getHitPoint()) {
        giveTurn(*subject);
        if(shotgun.isEmpty()) {
            object = &dealer;
            subject = &player;
            player.addRandomItems(rGetNum(1, 4));
            dealer.addRandomItems(rGetNum(1, 4));
            shotgun.loading(rGetNum(2, 4));
        } else {
            std::swap(object, subject);
        }
    }
}

void Session::giveTurn(Player &subject) {
    std::cout << "Enter\n0 - Shot\n1 - Use Item\nInput:";
    while(getInputBool() && subject.getItemCount()) {
        subject.getStats();
        std::cout << "Enter number item\nInput:";
        subject.useItem(getCorrectInt(0, subject.getItemCount() - 1));
        if (!subject.getHitPoint())
            return;
        std::cout << "Enter\n0 - Shoot\n1 - Use Item\nInput:";
    }
    std::cout << "Enter\n0 - Shoot Yourself\n1 - Shoot " << subject.getTarget()->getName() << std::endl;
    if(getInputBool())
        shotgun.shoot(subject.getTarget());
    else
        shotgun.shoot(subject);
}

void Session::setDealer(Player &dealer) {
    this->dealer = dealer;
}

void Session::setPlayer(Player &player) {
    this->player = dealer;
}
