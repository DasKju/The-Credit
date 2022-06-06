#include <sqlite3.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
//use.h

using std::stringstream;
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void get(){
  sqlite3* pDb = NULL;
  sqlite3_stmt* query = NULL;
  char *err_message = 0;
  int ret = 0;
do {
  if (SQLITE_OK != (ret = sqlite3_initialize()))
     {
         std::cout << "Failed to initialize library:" << ret;
         break;
     }
     if (SQLITE_OK != (ret = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
      {
        std::cout << "Failed to open conn:" << ret;
          break;
      }
      if (SQLITE_OK == (ret = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
       {
           std::cout << "Connecten Sucessfully to db \n";
       }
       std::cout << "Starting Request" << "\n";
     const char* sql = "SELECT * FROM TheCredit ";
     ret = sqlite3_exec(pDb, sql, callback, 0, &err_message);
     std::cout << "Requested" << "\n";
    if (ret != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", err_message);
     sqlite3_free(err_message);
   } if(ret == SQLITE_OK){
      fprintf(stdout, "Operation done successfully\n");
      sqlite3_close(pDb);
      sqlite3_shutdown();
    }
} while(false);
sqlite3_shutdown();
}
