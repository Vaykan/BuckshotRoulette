#include "myFrame.h"

#include "session.h"
#include "player.h"

MyFrame::MyFrame(Session& session) : wxFrame(NULL, wxID_ANY, "Buckshot Roulette"), session(&session) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizerHpObject = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerUpButton = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerText = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerMiddleButton = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerHpSubject = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerDownButton = new wxBoxSizer(wxHORIZONTAL);

    objectNameText = new wxStaticText(panel, wxID_ANY, "");
    sizerHpObject->Add(objectNameText, 0, wxALIGN_CENTER | wxALL, 0);

    objectHpText = new wxStaticText(panel, wxID_ANY, "");
    sizerHpObject->Add(objectHpText, 0, wxALIGN_CENTER | wxALL, 3);
    sizer->Add(sizerHpObject, 0, wxALIGN_CENTER | wxALL, 0);

    for (int i = 0; i < objectItemSlot.size(); ++i) {
        objectItemSlot[i] = new wxButton(panel, i + BUTTON_ITEM);
        objectItemSlot[i]->Bind(wxEVT_BUTTON, &MyFrame::OnObjectItemButtonClicked, this);
        sizerUpButton->Add(objectItemSlot[i], 0, wxALIGN_CENTER | wxALL, 5);
    }

    sizer->Add(sizerUpButton, 0, wxALIGN_CENTER | wxALL, 5);

    textCtrl = new wxTextCtrl(panel, wxID_ANY, wxT(""),
                              wxDefaultPosition, wxSize(300, 200),
                              wxTE_MULTILINE | wxTE_READONLY);

    sizerText->Add(textCtrl, 0, wxALIGN_CENTER | wxALL, 5);

    sizer->Add(sizerText, 0, wxALIGN_CENTER | wxALL, 5);

    shootButton = new wxButton(panel, wxID_ANY, wxT("Shoot"));
    shootButton->Bind(wxEVT_BUTTON, &MyFrame::OnShootButtonClicked, this);
    shootYourselfButton = new wxButton(panel, wxID_ANY, wxT("Shoot Yourself"));
    shootYourselfButton->Bind(wxEVT_BUTTON, &MyFrame::OnShootYourselfButtonClicked, this);

    sizerMiddleButton->Add(shootButton, 0, wxALIGN_CENTER | wxALL, 5);
    sizerMiddleButton->Add(shootYourselfButton, 0, wxALIGN_CENTER | wxALL, 5);
#ifndef NDEBUG
    if (IsDebuggerPresent()) {
        debugButton = new wxButton(panel, wxID_ANY, wxT("Debug Button: OFF"));
        debugButton->Bind(wxEVT_BUTTON, &MyFrame::OnDebugButtonClicked, this);
    }
#endif
    sizerMiddleButton->Add(debugButton, 0, wxALIGN_CENTER | wxALL, 5);

    sizer->Add(sizerMiddleButton, 0, wxALIGN_CENTER | wxALL, 5);

    subjectNameText = new wxStaticText(panel, wxID_ANY, "");
    sizerHpSubject->Add(subjectNameText, 0, wxALIGN_CENTER | wxALL, 0);

    subjectHpText = new wxStaticText(panel, wxID_ANY, "");
    sizerHpSubject->Add(subjectHpText, 0, wxALIGN_CENTER | wxALL, 3);
    sizer->Add(sizerHpSubject, 0, wxALIGN_CENTER | wxALL, 0);

    for (int i = 0; i < subjectItemSlot.size(); ++i) {
        subjectItemSlot[i] = new wxButton(panel, i);
        subjectItemSlot[i]->Bind(wxEVT_BUTTON, &MyFrame::OnSubjectItemButtonClicked, this);
        sizerDownButton->Add(subjectItemSlot[i], 0, wxALIGN_CENTER | wxALL, 5);
    }
    updateAllButtonText();
    updateHpStaticText();
    updateNameStaticText();

    sizer->Add(sizerDownButton, 0, wxALIGN_CENTER | wxALL, 5);

    panel->SetSizerAndFit(sizer);

    SetSizeHints(850, 490);

}

void MyFrame::OnDebugButtonClicked(wxCommandEvent& event) {
#ifndef NDEBUG
    if (IsDebuggerPresent()) {
        isDebugButtonActivated = !isDebugButtonActivated;
        debugButton->SetLabel(isDebugButtonActivated ?"Debug Button: ON" : "Debug Button: OFF");
    }
#endif
}

void MyFrame::OnObjectItemButtonClicked(wxCommandEvent& event) {
    if (!session->getPlayer().getHitPoint() || !session->getDealer().getHitPoint())
        return;

    Player& subject = session->getSubject();
    Player& object = session->getObject();
    int buttonID = event.GetId() - BUTTON_ITEM;

#ifndef NDEBUG
    if (IsDebuggerPresent()) {
        if (isDebugButtonActivated) {
            std::vector<Item*> itemStorage = object.getItemStorage();
            static int index = 0;

            if (index > itemStorage.size() - 1)
                index = 0;
            if (object.getItemCount() > buttonID)
                object.getItem()[buttonID] = itemStorage[index];
            else
                object.getItem().push_back(itemStorage[index]);

            index++;
            updateAllButtonText();
            return;
        }
    }
#endif

    if (subject.getIsAdrenalineActive() && object.getItemCount() > buttonID) {
        Item* correctItem = object.getItem()[buttonID];
        correctItem->setOwner(subject);
        object.useItem(buttonID);
        correctItem->setOwner(object);
        subject.setIsAdrenalineActive(false);
        session->setLastAction(USE_ITEM);
        session->checkTurn();
        updateAllButtonText();
        updateHpStaticText();
        updateNameStaticText();
    }
}


void MyFrame::OnSubjectItemButtonClicked(wxCommandEvent& event) {
    if (!session->getPlayer().getHitPoint() || !session->getDealer().getHitPoint())
        return;

    Player& subject = session->getSubject();
    int buttonID = event.GetId();

#ifndef NDEBUG
    if (IsDebuggerPresent()) {
        if (isDebugButtonActivated) {
            std::vector<Item*> itemStorage = subject.getItemStorage();
            static int index = 0;

            if (index > itemStorage.size() - 1)
                index = 0;
            if (subject.getItemCount() > buttonID)
                subject.getItem()[buttonID] = itemStorage[index];
            else
                subject.getItem().push_back(itemStorage[index]);

            index++;
            updateAllButtonText();
            return;
        }
    }
#endif

    if (subject.getItemCount() > buttonID) {
        subject.setIsAdrenalineActive(false);
        subject.useItem(buttonID);
        session->setLastAction(USE_ITEM);
        session->checkTurn();
        updateAllButtonText();
        updateHpStaticText();
        updateNameStaticText();
    }
}

void MyFrame::OnShootButtonClicked(wxCommandEvent& event) {
    if (!session->getPlayer().getHitPoint() || !session->getDealer().getHitPoint())
        return;
    Player& subject = session->getSubject();
    subject.setIsAdrenalineActive(false);
    session->shootTarget();
    session->setLastAction(SHOOT_TARGET);
    session->checkTurn();
    updateAllButtonText();
    updateHpStaticText();
    updateNameStaticText();
}

void MyFrame::OnShootYourselfButtonClicked(wxCommandEvent& event) {
    if (!session->getPlayer().getHitPoint() || !session->getDealer().getHitPoint())
        return;
    Player& subject = session->getSubject();
    subject.setIsAdrenalineActive(false);
    session->shootYourself();
    session->setLastAction(SHOOT_YOURSELF);
    session->checkTurn();
    updateAllButtonText();
    updateHpStaticText();
    updateNameStaticText();
}


void MyFrame::updateAllButtonText() {
    for (int i = 0; i < subjectItemSlot.size(); i++) {
        if (session->getSubject().getItemCount() > i) {
            subjectItemSlot[i]->SetLabel(session->getSubject().getItem()[i]->getName());
        } else {
            subjectItemSlot[i]->SetLabel(" ");
        }
    }
    for (int i = 0; i < objectItemSlot.size(); i++) {
        if (session->getObject().getItemCount() > i) {
            objectItemSlot[i]->SetLabel(session->getObject().getItem()[i]->getName());
        } else {
            objectItemSlot[i]->SetLabel(" ");
        }
    }
}

wxTextCtrl* MyFrame::getTextCtrl() {
    return textCtrl;
}

void MyFrame::updateHpStaticText() {
    std::string label = std::to_string(session->getObject().getHitPoint()) + " hp";
    objectHpText->SetLabel(label);
    label = std::to_string(session->getSubject().getHitPoint()) + " hp";
    subjectHpText->SetLabel(label);
}

void MyFrame::updateNameStaticText() {
    objectNameText->SetLabel(session->getObject().getName());
    subjectNameText->SetLabel(session->getSubject().getName());
}