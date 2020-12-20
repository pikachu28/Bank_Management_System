#include <iostream>
#include <sqlite3.h>
#include<string>
#include"db.h"
using namespace std;

string password,acc, changed, i, x;
int deposit=0;

void updateBal(int d){
    i = to_string(d);
    sql = "UPDATE customer SET Balance = '" + i + "' WHERE AccountNo='"+ acc +"'";
    rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    if(rc != SQLITE_OK){
        cout<<"\n\t\t\tYour balance is not updated"<<endl;
        }
        else{
            cout<<"\n\t\t\tYour balance has been updated"<<endl;
            tempdb.createTransactionTable(acc);
            tempdb.TransactionTable(acc);
        }
    }

static int callback_2(void* data, int argc, char** argv, char ** azColName){
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
            if((!colName.compare("Balance"))&(deposit!=0)){
                x = atoi(colValueString);
                changed = to_string(deposit);
                deposit = x + deposit;
                updateBal(deposit);
            }
        }
        return 0;
    }



void depositInBal(){
    cout<<"\n\t\t\tEnter the deposit: ";
    cin>>deposit;
    sql = "SELECT Balance FROM customer WHERE AccountNo='"+ acc +"'";
    rc = sqlite3_exec(db, sql.c_str(), callback_2, NULL, NULL);
    if(rc != SQLITE_OK){
        cout<<"\n\t\t\tCompleted"<<endl;
        }
}

void withdrawInBal(){
    int w;
    cout<<"\n\t\t\tEnter the amount to withdraw: ";
    cin>>w;
    deposit = w - 2*w;
    cout<<deposit<<endl;
    string withdraw = to_string(w);
    sql = "SELECT Balance FROM customer WHERE AccountNo='"+ acc +"' and Balance> '"+ withdraw +"'";
    rc = sqlite3_exec(db, sql.c_str(), callback_2, NULL, NULL);

}
bool database::viewTransactionDetails(string acc_no){
    x = "Transaction_"+acc_no;
    sql = "SELECT * FROM '"+ x +"'";
    rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    if(rc != SQLITE_OK){
        return false;
        }
     else{
            return true;
        }
}

void viewTransaction(){
    if(tempdb.viewTransactionDetails(acc)){
        sql = "SELECT * FROM '"+ x +"'";
        sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    }
    else{
        cout<<"Can not access your transaction.They may not exist if you have not made any transactions yet";
    }
}
bool custLogin(){
    cout<<"\n\t\t\tEnter your id: ";
    cin>>acc;
    cout<<"\n\t\t\tEnter password: ";
    cin>>password;
    sql = "Select *FROM customer WHERE AccountNo='"+ acc +"' and emp_password='"+ password +"'";
    rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    if(rc != SQLITE_OK){
        cout<<"\n\t\t\tIncorrect Account Id or password"<<endl;
        return false;
        }
        else{
            //write whatever function u wnat to perform in this block after login
            cout<<"\n\t\t\tLogin Sucessful";
            return true;
        }
    }

void database::createTransactionTable(string acc_no)
{
    x = "Transaction_"+acc_no;
	sql = "CREATE TABLE IF NOT EXISTS '"+ x +"' ("
        "TransactionID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"CURRENT_BALANCE VARCHAR(50) NOT NULL,"
		"AMOUNT_Deposit_withdraw VARCHAR(50) NOT NULL,"
        "DATE TEXT);";
	rc = sqlite3_exec(db, sql.c_str(),callback, NULL, NULL);	
	if (rc != SQLITE_OK) {
		cout << "\n\t\t\tError: " <<endl;
	}
	else{
		cout << "\n\t\t\tTable TRANSACTION exits!";
	}
	}


void database::TransactionTable(string acc_no){
    // int acc;
    // acc = stoi(acc_no);
    // string a = to_string(acc);
    x = "Transaction_"+acc_no;
    sql = "INSERT INTO '"+ x +"'(CURRENT_BALANCE, AMOUNT_Deposit_withdraw, DATE) VALUES ('"+ i +"','"+ changed +"', datetime('now', 'localtime'));";
    rc = sqlite3_exec(db, sql.c_str(),callback, NULL, NULL);	
	if (rc != SQLITE_OK) {
		cout << "\n\t\t\tError: " <<endl;
	}
	else{
		cout << "\n\t\t\tTransaction Completed";
	}
}