#include "db.h"
#include "db-use.h"
#include <iostream>
#include <fstream>
#include "search.h"
using namespace std;

int main(int argc, char const *argv[]) {

  if(!read_init){
    ofstream myfile;
    myfile.open ("db-init.txt");
    myfile << "true";
    myfile.close();
    initialize();
  }
  get();
  return 0;
}
