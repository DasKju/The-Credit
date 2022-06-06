#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/event.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

wxString command(wxString input ){
  if(std::string(input.mb_str()) == std::string("Test")){
    return "Das ist wahrscheinlich ein Test \n";
  }
  if(std::string(input.mb_str()) == std::string("")){
    return "";
  }
  std::string s_input = std::string(input.mb_str());
  std::string l_input{s_input};
  if(s_input.rfind("stock buy", 0) == 0){
    int i = l_input.length() - 1; // last character
    while (i != 0 && !isspace(l_input[i]))
    {
      --i;
    }
    std::string lastword = l_input.substr(i+1);
    return "You want to buy The Stock ?"+lastword+" \n";
  }
  return input+"\n";
}
