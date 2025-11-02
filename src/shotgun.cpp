#include "shotgun.h"
#include "session.h"
#include "aiManager.h"
#include "myFrame.h"

void Shotgun::shoot(Player* target, Player* shooter) {
    session->getMyFrame()->getTextCtrl()->AppendText("\n");
    if (target == shooter) {
        session->getMyFrame()->getTextCtrl()->AppendText(shooter->getName());
        session->getMyFrame()->getTextCtrl()->AppendText(" Shoot Yourself");
    } else {
        session->getMyFrame()->getTextCtrl()->AppendText(shooter->getName());
        session->getMyFrame()->getTextCtrl()->AppendText(" Shoots at ");
        session->getMyFrame()->getTextCtrl()->AppendText(target->getName());
    }

    if (magazine.back() == LIVE) {
        previousShellType = LIVE;
        session->getMyFrame()->getTextCtrl()->AppendText("\nSHOT!");
        if (doubleDamage)
            target->changeHitPoint(-2);
        else
            target->changeHitPoint(-1);
    } else {
        previousShellType = BLANK;
        session->getMyFrame()->getTextCtrl()->AppendText("\nCLICK!");
    }
    pumping();
    doubleDamage = false;
}

void Shotgun::pumping() {
    if (magazine.back() == LIVE)
        session->getMyFrame()->getTextCtrl()->AppendText("\nLIVE shell ejected");
    else
        session->getMyFrame()->getTextCtrl()->AppendText("\nBLANK shell ejected");
    magazine.pop_back();

    if (session->getSubject().getIsAI())
        session->getSubject().getAIManager().pumpingMagazine();
    if (session->getObject().getIsAI())
        session->getObject().getAIManager().pumpingMagazine();
}

void Shotgun::loading(int count) {
    if (session->getSubject().getIsAI())
        session->getSubject().getAIManager().loadMagazine(count);
    if (session->getObject().getIsAI())
        session->getObject().getAIManager().loadMagazine(count);

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

void Shotgun::displayMagazineContents() {
    int live = 0;
    int blank = 0;
    for (auto& i: magazine) {
        if (i == LIVE)
            live++;
        else
            blank++;
    }
    session->getMyFrame()->getTextCtrl()->AppendText("\n\nShotgun loaded:\n");
    session->getMyFrame()->getTextCtrl()->AppendText(std::to_string(live));
    session->getMyFrame()->getTextCtrl()->AppendText(" Live\n");
    session->getMyFrame()->getTextCtrl()->AppendText(std::to_string(blank));
    session->getMyFrame()->getTextCtrl()->AppendText(" Blank\n");
}

ShellType& Shotgun::getBackShell() {
    return magazine.back();
}

std::vector<ShellType>& Shotgun::getMagazine() {
    return magazine;
}

void Shotgun::setDoubleDamage(bool doubleDamage) {
    this->doubleDamage = doubleDamage;
}

void Shotgun::setSession(Session& session) {
    this->session = &session;
}

ShellType Shotgun::getPreviousShellType() {
    return previousShellType;
}