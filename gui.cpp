#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "utils/command.h"

#include "utils/db-init.h" 

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
  dbinit();
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
  wxTextCtrl    *test = new wxTextCtrl( this, wxID_ANY, "",
                            wxPoint(5,260), wxSize(1030,400),
                            wxTE_MULTILINE | wxTE_READONLY);
    wxTextCtrl* upperOnly = new wxTextCtrl(this, wxID_ANY, wxT(""),
                                           wxPoint(5,260), wxSize(1030,30),wxTE_PROCESS_ENTER);
    upperOnly->Bind(wxEVT_TEXT_ENTER, [test, upperOnly](wxCommandEvent&) {
      wxString input = upperOnly -> GetValue();
      *test << command(input);
      upperOnly ->SetValue("");
     });




    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer -> Add(test, 1, wxALL | wxEXPAND, 10 );
    sizer -> Add( upperOnly, 0.25, wxALL | wxEXPAND, 10 );
     wxSizer *sizer_bottom = new wxBoxSizer(wxVERTICAL);
         this->SetSizerAndFit(sizer);

}
