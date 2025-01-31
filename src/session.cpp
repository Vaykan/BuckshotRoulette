#include "session.h"

void Session::config() {
    dealer.setName("Dealer");
    dealer.setTarget(player);
    dealer.setShotgun(shotgun);
    dealer.setMaxHitPoint(4);
    dealer.setItemStorage({new Pill(), new Cigarette(), new Beer(), new Adrenaline(), new Magnifier(), new Handcuffs(),
                           new Inverter(), new Saw(), new Phone()});
    for (auto& i: dealer.getItemStorage()) {
        i->setOwner(dealer);
    }
    dealer.setArrayItemSize(8);

    player.setName("Player");
    player.setTarget(dealer);
    player.setShotgun(shotgun);
    player.setMaxHitPoint(4);
    player.setItemStorage({new Pill(), new Cigarette(), new Beer(), new Adrenaline(), new Magnifier(), new Handcuffs(),
                           new Inverter(), new Saw(), new Phone()});
    for (auto& i: player.getItemStorage()) {
        i->setOwner(player);
    }
    player.setArrayItemSize(8);
}

void Session::start() {
    Player* object;
    Player* subject;

    object = &dealer;
    subject = &player;

    dealer.setHitPoint(4);
    player.setHitPoint(4);

    int countItem = rGetNum(1, 4);
    player.addRandomItems(countItem);
    dealer.addRandomItems(countItem);

    shotgun.loading(rGetNum(2, 8));
    shotgun.displayMagazineContents();

    while (player.getHitPoint() && dealer.getHitPoint()) {
        if (subject->isSkipTurn()) {
            std::cout << subject->getReasonSkipTurn();
            subject->decreaseSkipTurn();
        } else {
            subject->setIsHandcuffed(false);
            giveTurn(*subject);
        }
        if (shotgun.isEmpty()) {
            object = &dealer;
            subject = &player;
            countItem = rGetNum(1, 4);
            player.addRandomItems(countItem);
            dealer.addRandomItems(countItem);
            shotgun.loading(rGetNum(2, 8));
            shotgun.displayMagazineContents();
        } else {
            std::swap(object, subject);
        }
    }
    if (!player.getHitPoint())
        std::cout << "\nPlayer dead\n";
    else if (!dealer.getHitPoint())
        std::cout << "\nDealer dead\n\n";

}

void Session::giveTurn(Player& subject) {
    subject.getStats();
    subject.getTarget()->getStats();
    std::cout << "Enter\n0 - Shot\n1 - Use Item\nInput:";
    while (getInputBool() && subject.getItemCount()) {
        subject.getStats();
        subject.getTarget()->getStats();
        std::cout << "Enter number item\nInput:";
        subject.useItem(getCorrectInt(0, subject.getItemCount() - 1));
        if (player.isDead() || dealer.isDead() || shotgun.isEmpty())
            return;
        std::cout << "Enter\n0 - Shoot\n1 - Use Item\nInput:";
        std::cout << "\n\n";
    }
    std::cout << "\n\n";
    std::cout << "Enter\n0 - Shoot Yourself\n1 - Shoot " << subject.getTarget()->getName() << "\nInput: ";
    if (getInputBool()) {
        shotgun.shoot(subject.getTarget());
    } else {
        if (shotgun.getBackShell() == BLANK)
            subject.getTarget()->addSkipTurn("");
        shotgun.shoot(&subject);
    }
}

void Session::setDealer(Player& dealer) {
    this->dealer = dealer;
}

void Session::setPlayer(Player& player) {
    this->player = player;
}