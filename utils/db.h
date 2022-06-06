 #include <sqlite3.h>
 #include <iostream>
 #include <string>
 #include <stdlib.h>
 #include <stdio.h>
 #include <sstream>
 bool found = false; using std::stringstream;
//db.h
 using namespace std;
int initialize(){
  sqlite3* pDb = NULL;
  sqlite3_stmt* query = NULL;
  char *err_message = 0;
  int ret = 0;
  do {
    if (SQLITE_OK != (ret = sqlite3_initialize()))
       {
           cout << "Failed to initialize library:" << ret;
           break;
       }
       if (SQLITE_OK != (ret = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))) {
            cout << "Failed to open conn:" << ret;
            break;
        }
        if (SQLITE_OK == (ret = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
         {
             cout << "Connecten Sucessfully to db \n";
         }


  } while(false);
  do {

      int rc = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if (rc != SQLITE_OK) {
        std::cout << "Connectin to database Faild" << '\n';
      }
      const char *sql_query = "DROP TABLE IF EXISTS TheCredit;"
      "CREATE TABLE TheCredit(ID INT PRIMARY KEY NOT NULL,Company TEXT NOT NULL, Name TEXT NOT NULL, CEO TEXT NOT NULL,  PE INT  NOT NULL, Amount INT NOT NULL, Value INT NOT NULL);";
      rc = sqlite3_exec(pDb, sql_query, 0, 0, &err_message);
      if (rc != SQLITE_OK) {
        std::cout << "Error Massage: " << err_message << '\n';
      }
      if(rc==SQLITE_OK){
        std::cout << "Table TheCredit created successfully" << '\n';
        const char *sql_ = "INSERT INTO TheCredit (ID, Company, Name, CEO,PE, Amount, Value) VALUES (1, 'dasKju', 'Kju', 'Benn1x',12, 1200, 2000)";
        rc = sqlite3_exec(pDb, sql_, 0, 0, &err_message);
        if (rc != SQLITE_OK) {
          std::cout << "Error Massage: " << err_message << '\n';
        }
        else{
          std::cout << "The Value where successfully uploaded" << '\n';}
      }
    }while(false);
    if (NULL != query) sqlite3_finalize(query);
    if (NULL != pDb) sqlite3_close(pDb);
    sqlite3_close(pDb);
    sqlite3_shutdown();
    return ret;
}
