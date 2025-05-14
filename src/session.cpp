#include "session.h"

void Session::config() {
    dealer.setName("Dealer");
    dealer.setTarget(player);
    dealer.setShotgun(shotgun);
    dealer.setMaxHitPoint(4);
    dealer.setItemStorage({new Pill(), new Cigarette(), new Beer(), new Magnifier(), new Handcuffs(),
                           new Inverter(), new Saw(), new Phone(), new Adrenaline()});
    for (auto& i: dealer.getItemStorage()) {
        i->setOwner(dealer);
    }
    dealer.setArrayItemSize(8);

    player.setName("Player");
    player.setTarget(dealer);
    player.setShotgun(shotgun);
    player.setMaxHitPoint(4);
    player.setItemStorage({new Pill(), new Cigarette(), new Beer(), new Magnifier(), new Handcuffs(),
                           new Inverter(), new Saw(), new Phone(), new Adrenaline()});
    for (auto& i: player.getItemStorage()) {
        i->setOwner(player);
    }
    player.setArrayItemSize(8);

    //set from start()

    object = &dealer;
    subject = &player;

    int randomCount = rGetNum(2, 4);
    dealer.setHitPoint(randomCount);
    player.setHitPoint(randomCount);

    randomCount = rGetNum(1, 4);
    player.addRandomItems(randomCount);
    dealer.addRandomItems(randomCount);

    shotgun.loading(rGetNum(2, 8));

}

void Session::start() {
    // copy that in config()
    // |
    // v
    object = &dealer;
    subject = &player;

    dealer.setHitPoint(4);
    player.setHitPoint(4);

    int countItem = rGetNum(1, 4);
    player.addRandomItems(countItem);
    dealer.addRandomItems(countItem);

    shotgun.loading(rGetNum(2, 8));
    // ^
    // |
    // copy that in config()
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
            randomCount = rGetNum(1, 4);
            player.addRandomItems(randomCount);
            dealer.addRandomItems(randomCount);
            shotgun.loading(rGetNum(2, 8));
            shotgun.displayMagazineContents();
        } else {
            std::swap(object, subject);
        }
    }
    if (!player.getHitPoint())
        myFrame->getTextCtrl()->AppendText("\nPlayer dead\n");
    else if (!dealer.getHitPoint())
        myFrame->getTextCtrl()->AppendText("\nDealer dead\n\n");
}

void Session::giveTurn(Player& subject) {
    subject.getStats();
    subject.getTarget()->getStats();
    while (getInputBool() && subject.getItemCount()) {
        subject.getStats();
        subject.getTarget()->getStats();
        subject.useItem(getCorrectInt(0, subject.getItemCount() - 1));
        if (player.isDead() || dealer.isDead() || shotgun.isEmpty())
            return;
    }
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

Player& Session::getDealer() {
    return dealer;
}

Player& Session::getPlayer() {
    return player;
}

Player& Session::getObject(){
    return *object;
}

Player& Session::getSubject() {
    return *subject;
}

void Session::setMyFrame(MyFrame& myFrame) {
    this->myFrame = &myFrame;
}

MyFrame* Session::getMyFrame() {
    return myFrame;
}
