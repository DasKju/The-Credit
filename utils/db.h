 #include <sqlite3.h>
 #include <iostream>
 #include <string>
 #include <stdlib.h>
 #include <stdio.h>

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
       if (SQLITE_OK != (ret = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
        {
            cout << "Failed to open conn:" << ret;
            break;
        }
        if (SQLITE_OK == (ret = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
         {
             cout << "Connecten Sucessfully to db \n";
         }
        if (SQLITE_ROW != (ret = sqlite3_step(query)))
        {
            cout << "Failed to step: " << ret << " " << sqlite3_errmsg(pDb);
            break;
        }

        cout << "Value from sqlite: " << sqlite3_column_text(query, 0)<<"\n";

  } while(false);
  do {
    const char *sql = "SELECT 1 FROM sqlite_master where type='table' and name=TheCredit";
    int rc = sqlite3_prepare_v2(pDb, sql, -1, &query, NULL);
    sqlite3_bind_text(query, 1, "TheCredit", -1, SQLITE_TRANSIENT);
    rc = sqlite3_step(query);
    if(rc==SQLITE_ROW){
      std::cout << "Table found" << '\n';
    }else{
      int rc = sqlite3_open_v2("TheCredit.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if (rc != SQLITE_OK) {
        std::cout << "Connectin to database Faild" << '\n';
      }
      char *sql_query = "DROP TABLE IF EXISTS TheCredit;"
      "CREATE TABLE TheCredit(ID INT PRIMARY KEY NOT NULL,Company TEXT NOT NULL, Name TEXT NOT NULL, CEO TEXT NOT NULL,  PE INT  NOT NULL, Amount INT NOT NULL, Value INT NOT NULL);";
      rc = sqlite3_exec(pDb, sql_query, 0, 0, &err_message);
      if (rc != SQLITE_OK) {
        std::cout << "Error Massage: " << err_message << '\n';
      }
      else{
        std::cout << "Table TheCredit created successfully" << '\n';
      }
    }
  } while(false);
    if (NULL != query) sqlite3_finalize(query);
    if (NULL != pDb) sqlite3_close(pDb);
    sqlite3_shutdown();
    return ret;
}
