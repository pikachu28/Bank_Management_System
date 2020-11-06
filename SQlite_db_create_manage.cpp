//
//  main.cpp
//  SQLConnect
//
//  Created by Anjali Singh on 06/11/20.
//

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
//    string sql = "CREATE TABLE PERSON("
//    "ID INT PRIMARY KEY NOT NULL,"
//    "NAME TEXT NOT NULL,"
//    "SURNAME TEXT NOT NULL,"
//    "AGE INT NOT NULL);";
    rc = sqlite3_open("test.db", &db);
    char* messageError;
//    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);    //To create Table
    // CHECKING IF DB CREATED SUCCESSFULLY
//    if(rc){
//        cout<<"Can't open database:"<<sqlite3_errmsg(db)<<endl;
//        return -1;
//    }
//    else{
//        cout<<"Opened database successfully\n";
//    }
//    if(rc != SQLITE_OK){
//        cout<<"Error Create Table"<<endl;
//        sqlite3_free(messageError);
//    }
//    else{
//        cout<<"Table Create Successfully"<<endl;
//    }
    string query = "SELECT * FROM PERSON;";
    cout<<"Table before insertion";
    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
    string sql = "INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30);";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
    if(rc != SQLITE_OK){
        cout<<"Error Insert"<<endl;
        sqlite3_free(messageError);
    }
    sql = "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20);";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
    if(rc != SQLITE_OK){
        cout<<"Error Insert"<<endl;
        sqlite3_free(messageError);
    }
    sql = "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24);";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
    if(rc != SQLITE_OK){
        cout<<"Error Insert"<<endl;
        sqlite3_free(messageError);
    }
    else{
        cout<<"Records created Successfullly"<<endl;
    }
        sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
        sql = "DELETE FROM PERSON WHERE ID = 2;";
        rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
        if(rc != SQLITE_OK){
            cout<<"Error Delete "<<endl;
            sqlite3_free(messageError);
        }
        else{
            cout<<"Record Delete Successfully"<<endl;
        }
        
    
    rc = sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
      
    sqlite3_close(db);
    return 0;
}
