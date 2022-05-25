#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool read_init() {
  string line;
  ifstream myfile ("db-init.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      if(line == "true"){
        return true;
      }
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return false;
}
