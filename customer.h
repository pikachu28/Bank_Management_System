#include <iostream>
#include <sqlite3.h>
#include<string>
#include "db.h"
using namespace std;

database tempdb;
static int check = 0;
string pass, name, gender, mobile, DOB;
int acc_no;
float balance;


int database::insertCustData(int acc_no, string name, float balance, string dob, string ph_no, string gender, string pass)
{
	string com = "','";
	string no = to_string(acc_no);
	string bal = to_string(balance);
	string s = "INSERT INTO customer VALUES('" + no + com + name + "'," + bal + ",'" + dob + com + ph_no + com + gender + com + pass + "' );";
	rc = sqlite3_exec(db, s.c_str(), callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		cout << "Insert Error: " <<endl;
		return 0;
	}
	else {
		cout << "-> Record inserted successfully!" << endl;
		return 1;
	}
}

void NewAccount(){
    system("clear");
    cout << "\n\t\t\t-NEW ACCOUNT REGISTRATION- \n";
    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acc_no;
    cout << "\n\t\t\tEnter password : ";
    cin >> pass;
    cout << "\n\t\t\tName of the Account holder : ";
    cin.ignore();
    cin >> name;
    cout << "\n\t\t\tGender : ";
    cin >> gender;
    cout << "\n\t\t\tMobile No. : ";
    cin >> mobile;
    cout << "\n\t\t\tDate of Birth (YYYY/MM/DD): ";
    cin >> DOB;
    cout << "\n\t\t\tEnter The Initial Balance : ";
    cin >> balance;
    check = tempdb.insertCustData(acc_no, name, balance, DOB, mobile, gender, pass);
    if (check)
        cout << "\n\n\t\t\tYour Account has been created Successfully!";
    else
        cout << "\n\t\tError in creating a new account. We apologise..";
}

int database::updateCustData(int acc_no, string name, string dob, string ph_no)
{
	string ac_no = to_string(acc_no);
	sql = "UPDATE customer SET Name='" + name + "',DoB='" + dob + "',PhoneNo='" + ph_no + "' WHERE AccountNo='" + ac_no + "';";
	rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		cout << "Update Error: " << endl;
		return 0;
	}
	else {
		cout << "-> Record updated successfully!" << endl;
		return 1;
	}
}

void updateDetails(){
    system("clear");
    cout << "\n\t\t\t-UPDATE DETAILS- \n";

    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acc_no;
    cout << "\n\t\t\tENTER THE UPDATED DETAILS:-";
    cout << "\n\t\t\tName of the Account holder : ";
    cin.ignore();
    cin >> name;
    cout << "\n\t\t\tGender : ";
    cin >> gender;
    cout << "\n\t\t\tMobile No. : ";
    cin >> mobile;
    cout << "\n\t\t\tDate of Birth (YYYY/MM/DD): ";
    cin >> DOB;
    check = tempdb.updateCustData(acc_no, name, DOB, mobile);
    if (check)
        cout << "\n\n\t\t\tDetails have been updated!";
    else
        cout << "\n\t\tError in updating details. We apologise..";

}
int database::getCustData(int acc_no)
{
	string ac_no = to_string(acc_no);
	sql = "SELECT * FROM customer WHERE AccountNo=" + ac_no + ";";
	rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    if(rc!=SQLITE_OK){
        return 0;
    }
    else{
        return 1;
    }
}

void viewCustDetails(){
    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acc_no;
    check = tempdb.getCustData(acc_no);
    if(check==0){
        cout<<"Account number does not exist";
    } 
}

void viewCustTable(){
    sql = "SELECT * FROM customer";
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
}

int database::deleteCustData(int acc_no)
{
	string ac_no = to_string(acc_no);
	sql = "DELETE FROM customer WHERE AccountNo='" + ac_no + "';";
	rc = sqlite3_exec(db, sql.c_str(),callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		cout << "Delete Error: " <<endl;
		return 0;
	}
	else {
		cout << "-> Record deleted successfully!" << endl;
		return 1;
	}
}

void closeAcc(){
    cout<<"\n\t\t\tEnter the Account No.";
    cin>>acc_no;
    check =  tempdb.deleteCustData(acc_no);
}
