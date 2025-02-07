#include "myFrame.h"

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Buckshot Roulette") {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* itemSlot[8];
    for (auto& i : itemSlot) {
        i = new wxButton(panel, wxID_EXIT, wxT(" "));
        sizer->Add(i, 1, wxALIGN_TOP | wxALL, 5);
    }

    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, wxT(""),
                                          wxDefaultPosition, wxSize(300, 150),
                                          wxTE_MULTILINE | wxTE_READONLY);

    sizer->Add(textCtrl, 1, wxALIGN_TOP | wxALL, 10);

    panel->SetSizerAndFit(sizer);
}