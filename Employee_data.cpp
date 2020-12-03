#include <iostream>
#include <sqlite3.h>
using namespace std;

extern string N;

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

int main(int argc, const char * argv[]){
    sqlite3 *db;
    int rc=0;
    rc = sqlite3_open("test.db", &db);
    char* messageError;
    string Name ="SELECT NAME FROM PERSON";
    sqlite3_exec(db, Name.c_str(), callback, NULL, NULL);
    string n="STEVE";
    string Search = "SELECT * FROM PERSON WHERE Name='"+ n +"'";
    sqlite3_exec(db, Search.c_str(), callback, NULL, NULL);
    sqlite3_close(db);
    return 0;
}