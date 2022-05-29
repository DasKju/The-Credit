
#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/event.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Logo.xpm"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("The Credit", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}


MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
  SetIcon(wxICON(logo));
  wxMenuBar *menubar;
       wxMenu *file;
       wxMenu *help;
       wxTextCtrl *textctrl;
  wxPanel *panel = new wxPanel(this, -1);
  menubar = new wxMenuBar;
  file = new wxMenu;
  help = new wxMenu;

  menubar->Append(file, wxT("&Options"));
  menubar->Append(help, wxT("&Help"));
  SetMenuBar(menubar);
  wxTextCtrl    *test = new wxTextCtrl( this, wxID_ANY, "This is the log window.\n",
                            wxPoint(5,260), wxSize(630,100),
                            wxTE_MULTILINE | wxTE_READONLY);
    test -> SetBackgroundColour(wxColor(33, 33, 91));
    wxTextCtrl* upperOnly = new wxTextCtrl(this, wxID_ANY, wxT("Test"),
                                           wxPoint(5,260), wxSize(630,30),wxTE_PROCESS_ENTER);
    upperOnly->Bind(wxEVT_TEXT_ENTER, [test, upperOnly](wxCommandEvent&) {
      *test << "i work, Value: "<< upperOnly -> GetValue() << "\n";

     });
    wxPanel *panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_top->SetBackgroundColour(wxColor(33, 33, 31));




    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(panel_top, 2.5, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);
    sizer -> Add(test, 1, wxALL | wxEXPAND, 10 );
    sizer -> Add( upperOnly, 0.25, wxALL, 10 );
     wxSizer *sizer_bottom = new wxBoxSizer(wxVERTICAL);
         this->SetSizerAndFit(sizer);

}
