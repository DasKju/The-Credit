#include "db.h"
#include "db-use.h"
#include <iostream>
#include <fstream>
#include "search.h"
using namespace std;

void dbinit() {

  if(!read_init()){
    set();
    initialize();
  }
  get();
}
