#include "myFrame.h"

MyFrame::MyFrame(Session& session) : wxFrame(NULL, wxID_ANY, "Buckshot Roulette"), session(session){
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizerUpButton = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerText = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerMiddleButton = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerDownButton = new wxBoxSizer(wxHORIZONTAL);

    for (auto& i : objectItemSlot) {
        i = new wxButton(panel, wxID_ANY, wxT("ADRENALINE"));
        sizerUpButton->Add(i, 0, wxALIGN_CENTER | wxALL, 5);
    }
    sizer->Add(sizerUpButton, 0, wxALIGN_CENTER | wxALL, 5);

    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, wxT("ighoerhferoiferopferpfjerjpfjerpfjerpjfperpfjerpfripo"),
                                          wxDefaultPosition, wxSize(300, 200),
                                          wxTE_MULTILINE | wxTE_READONLY);

    sizerText->Add(textCtrl, 0, wxALIGN_CENTER | wxALL, 5);

    sizer->Add(sizerText, 0, wxALIGN_CENTER | wxALL, 5);

    wxButton* shootButton = new wxButton(panel, wxID_ANY, wxT("Shoot"));
    wxButton* shootYourselfButton = new wxButton(panel, wxID_ANY, wxT("Shoot Yourself"));

    sizerMiddleButton->Add(shootButton, 0, wxALIGN_CENTER | wxALL, 5);
    sizerMiddleButton->Add(shootYourselfButton, 0, wxALIGN_CENTER | wxALL, 5);

    sizer->Add(sizerMiddleButton, 0, wxALIGN_CENTER | wxALL, 5);

    for (int i = 0; i < subjectItemSlot.size(); ++i) {
        subjectItemSlot[i] = new wxButton(panel, i);
        subjectItemSlot[i]->Bind(wxEVT_BUTTON, &MyFrame::OnAnyButtonClicked, this);
        sizerDownButton->Add(subjectItemSlot[i], 0, wxALIGN_CENTER | wxALL, 5);
    }

    updateAllButtonName();

    sizer->Add(sizerDownButton, 0, wxALIGN_CENTER | wxALL, 5);

    panel->SetSizerAndFit(sizer);

    SetSizeHints(850, 390);
}

void MyFrame::OnAnyButtonClicked(wxCommandEvent& event) {
    Player* subject = &session.getSubject();
    int buttonID = event.GetId();

    if (subject->getItemCount() > buttonID) {
        subject->useItem(buttonID);
        updateAllButtonName();
    }
}

void MyFrame::setSession(Session& session) {
    this->session = session;
}

void MyFrame::updateAllButtonName() {
    for (int i = 0; i < subjectItemSlot.size(); i++) {
        if (session.getSubject().getItemCount() > i) {
            subjectItemSlot[i]->SetLabel(session.getSubject().getItem()[i]->getName());
        } else {
            subjectItemSlot[i]->SetLabel(" ");
        }
    }
    for (int i = 0; i < objectItemSlot.size(); i++) {
        if (session.getObject().getItemCount() > i) {
            objectItemSlot[i]->SetLabel(session.getObject().getItem()[i]->getName());
        } else {
            objectItemSlot[i]->SetLabel(" ");
        }
    }
}