#include "myFrame.h"

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Buckshot Roulette") {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizerUpButton = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerText = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerMiddleButton = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizerDownButton = new wxBoxSizer(wxHORIZONTAL);

    wxButton* objectItemSlot[8];
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

    wxButton* subjectItemSlot[8];
    for (auto& i : subjectItemSlot) {
        i = new wxButton(panel, wxID_ANY, wxT("ADRENALINE"));
        sizerDownButton->Add(i, 0, wxALIGN_CENTER | wxALL, 5);
    }

    sizer->Add(sizerDownButton, 0, wxALIGN_CENTER | wxALL, 5);

    panel->SetSizerAndFit(sizer);

    SetSizeHints(850, 390);
}