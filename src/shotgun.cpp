#include "shotgun.h"
#include "session.h"

void Shotgun::shoot(Player* target) {
    session->getMyFrame()->getTextCtrl()->AppendText("\n\n");
    if (magazine.back() == LIVE) {
        previousShellType = LIVE;
        session->getMyFrame()->getTextCtrl()->AppendText("SHOT!\n");
        if (doubleDamage)
            target->changeHitPoint(-2);
        else
            target->changeHitPoint(-1);
    } else {
        previousShellType = BLANK;
        session->getMyFrame()->getTextCtrl()->AppendText("CLICK!\n");
    }
    pumping();
    doubleDamage = false;
}

void Shotgun::pumping() {
    if (magazine.back() == LIVE)
        session->getMyFrame()->getTextCtrl()->AppendText("LIVE shell ejected\n");
    else
        session->getMyFrame()->getTextCtrl()->AppendText("BLANK shell ejected\n");
    magazine.pop_back();
    session->getMyFrame()->getTextCtrl()->AppendText("\n\n");
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

void Shotgun::displayMagazineContents() {
    int live = 0;
    int blank = 0;
    for (auto& i: magazine) {
        if (i == LIVE)
            live++;
        else
            blank++;
    }
    session->getMyFrame()->getTextCtrl()->AppendText("Shotgun loaded:\n");
    session->getMyFrame()->getTextCtrl()->AppendText(std::to_string(live));
    session->getMyFrame()->getTextCtrl()->AppendText(" Live\n");
    session->getMyFrame()->getTextCtrl()->AppendText(std::to_string(blank));
    session->getMyFrame()->getTextCtrl()->AppendText(" Blank\n\n");
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