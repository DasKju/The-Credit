// db.h providing the db
#include "db.h"
// db-use.h providing the use of the db
#include "db-use.h"
// search.h provides the functions for searhing in a .txt file
#include "search.h"

#include <iostream>
#include <fstream>

using namespace std;

void dbinit() {

  if(!read_init()){
    set();
    initialize();
  }
  get();
}
