#include<iostream>
#include<sqlite3.h>
#include<string>

using namespace std;

char* err;
int deposit=0;
sqlite3* db;
int status = 0;

static int callback_2(void* data, int argc, char** argv, char ** azColName){
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
         cout<<colName<<" = "<<colValueString<<endl;
        }
    cout<<endl;
    return 0;
    }

void update(int d){
    string i = to_string(d);
    cout<<endl<<i;
    string id = "1";
    string sql = "UPDATE customer SET Bal = '" + i + "' WHERE custID='"+ id +"'";
    status = sqlite3_exec(db, sql.c_str(), callback_2, NULL, NULL);
    if(status != SQLITE_OK){
        cout<<"You are not an admin"<<endl;
        sqlite3_free(err);
        }
        else{
            cout<<"Welcome"<<endl;
        }

}
    static int callback(void* data, int argc, char** argv, char ** azColName){
        string colName;
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
            int x;
            if((!colName.compare("Bal"))&(deposit!=0)){
                x = atoi(colValueString);
                deposit = x + deposit;
                cout<<colName<<" = "<<deposit<<endl;
                update(deposit);
            }
            else{
            cout<<colName<<" = "<<colValueString<<endl;
            }
        }
        cout<<endl;
        return 0;
    }



void getBal(){
    int status = sqlite3_open("BANK.db", &db);
	if (status) {
		cout<<"Can't open database: \n"<<sqlite3_errmsg(db);
	}
	else {
		cout<<"Opened database successfully!\n";
	}
    string id, n;
    cout<<"Enter the cust id: ";
    cin>>id;
    string sql = "SELECT *FROM customer WHERE custID='"+ id +"'";
    sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    cout<<endl<<"Enter the value want to deposit: ";
    cin>>deposit;
    sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
}


int main(){
    getBal();
    return 0;
}
