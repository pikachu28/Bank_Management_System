//
//  main.cpp
//  SQLConnect
//
//  Handled By Mitali and Binwant 
//

// ROLE_ID:
// 1: Adminstrator
// 2: Users
// 3: Employees
// 4: Managers

#include <iostream>
#include <sqlite3.h>
using namespace std;

static int callback(void* data, int argc, char** argv, char ** azColName){
    cout<<data<<endl;
    char* colName;
    char* colValueString;
    char* y;
    for(int i=0; i<argc; i++){
        colName = azColName[i];
        colValueString = argv[i];
        if(colValueString==0){
            y = NULL;
        }
        else{
            y = colValueString;
        }
        cout<<colName<<"="<<colValueString;
    }
    cout<<endl;
    return 0;
}
int main(int argc, const char * argv[]) {
    sqlite3 *db;
    int rc=0;
//    $ g++ createDB.cpp -l sqlite3
//    $ ./a.out
//    string sql = "CREATE TABLE LOGIN("
//    "login_id INT PRIMARY KEY,"
//    "login_role_id INT NOT NULL,"
//    "login_username VARCHAR(255) UNIQUE NOT NULL,"
//    "user_password VARCHAR(255) UNIQUE NOT NULL);";
    rc = sqlite3_open("test.db", &db);
    char* messageError;
    // rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);    //To create Table
    // CHECKING IF DB CREATED SUCCESSFULLY
//    if(rc){
//        cout<<"Can't open database:"<<sqlite3_errmsg(db)<<endl;
//        return -1;
//    }
//    else{
//        cout<<"Opened database successfully\n";
//    }
// CHECKING IF Table is build successfully
   if(rc != SQLITE_OK){
       cout<<"Error Create Table"<<endl;
       sqlite3_free(messageError);
   }
   else{
       cout<<"Table Create Successfully"<<endl;
   }
    string query = "SELECT * FROM LOGIN";
    cout<<"Table before insertion";
    sqlite3_exec(db, query.c_str(), callback, NULL, NULL); //to view table
    string sql = "INSERT INTO LOGIN VALUES(1, 3, 'CHANDLER', '30');";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
    if(rc != SQLITE_OK){
        cout<<"Error Insert"<<endl;
        sqlite3_free(messageError);
    }
    sql = "INSERT INTO LOGIN VALUES(2, 2, 'MONICA', '20');";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
    if(rc != SQLITE_OK){
        cout<<"Error Insert"<<endl;
        sqlite3_free(messageError);
    }
    sql = "INSERT INTO LOGIN VALUES(3, 4, 'ROSS', '24');";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
    if(rc != SQLITE_OK){
        cout<<"Error Insert"<<endl;
        sqlite3_free(messageError);
    }
    else{
        cout<<"Records created Successfullly"<<endl;
    }
        sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
        // sql = "DELETE FROM PERSON WHERE ID = 2;";
        // rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
        // if(rc != SQLITE_OK){
        //     cout<<"Error Delete "<<endl;
        //     sqlite3_free(messageError);
        // }
        // else{
        //     cout<<"Record Delete Successfully"<<endl;
        // }
        // rc = sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
        // string Name ="SELECT NAME FROM PERSON";
        // sqlite3_exec(db, Name.c_str(), callback, NULL, NULL);
    
    
      
    sqlite3_close(db);
    return 0;
}
