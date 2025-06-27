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

    object = &dealer;
    subject = &player;

    int randomCount = rGetNum(2, 4);
    dealer.setHitPoint(randomCount);
    player.setHitPoint(randomCount);

    randomCount = rGetNum(1, 4);

    player.addRandomItems(randomCount);
    dealer.addRandomItems(randomCount);

    shotgun.setSession(*this);
    shotgun.loading(rGetNum(2, 8));
}

Player& Session::getDealer() {
    return dealer;
}

Player& Session::getPlayer() {
    return player;
}

Player& Session::getObject() {
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

void Session::displayShotgunMagazineContents() {
    shotgun.displayMagazineContents();
}

void Session::checkTurn() {
    if (!player.getHitPoint()) {
        myFrame->getTextCtrl()->AppendText("Player dead");
        return;
    } else if (!dealer.getHitPoint()) {
        myFrame->getTextCtrl()->AppendText("Dealer dead");
        return;
    }
    if (shotgun.isEmpty()) {
        subject = &player;
        object = &dealer;
        shotgun.loading(rGetNum(2, 8));
        shotgun.displayMagazineContents();
        int randomCount = rGetNum(1, 4);
        player.addRandomItems(randomCount);
        dealer.addRandomItems(randomCount);
    } else if (lastAction == SHOOT_TARGET || lastAction == SHOOT_YOURSELF && shotgun.getPreviousShellType() == LIVE) {
        if (object->isSkipTurn()) {
            myFrame->getTextCtrl()->AppendText(object->getReasonSkipTurn());
            object->decreaseSkipTurn();
        } else {
            object->setIsHandcuffed(false);
            swapTurn();
        }
    }
    lastAction = NODATA;
}

void Session::swapTurn() {
    std::swap(subject, object);
}

void Session::shootTarget() {
    shotgun.shoot(object);
}

void Session::shootYourself() {
    shotgun.shoot(subject);
}

void Session::setLastAction(Action lastAction) {
    this->lastAction = lastAction;
}