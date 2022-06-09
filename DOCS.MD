# TheCredit

## GUI

Using WxWidgets to make a Frame with 2 Panels, test and upperOnly
test is the Log Panel and upperOnly the Input

The Database initilizing is made with dbinit() this command get Providet by The utils/db-init.h file

## utils/db-init.h

Using db.h for initilizing the Database
db-use to provide simple features to get data from the Database
search.h makes it possible to search in the db-init.txt file after the word `true`

## utils/db.h // utils/db-use.h

sqlite3.h is providing the features for the local database
(i guess the code is self explaining trough the error massanges)

## utils/search.h

with fstream open the file and if any lines is just true it returns the value true
