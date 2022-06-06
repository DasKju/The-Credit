#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool read_init() {
  string line;
  ifstream myfile;
  myfile.open ("db-init.txt");

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      if(line == "true"){
        cout << "Value is True!" << "\n";
        myfile.close();
        cout << "File Closed"<< "\n";
        return true;
      }
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return false;
}
void set(){
  std::cout << "Bin hier" << '\n';
  ofstream myfile;
  myfile.open ("db-init.txt");
  myfile << "true";
  myfile.close();
}
