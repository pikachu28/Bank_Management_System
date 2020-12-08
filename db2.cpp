#include<iostream>
#include"sqlite3.h"
#include"db.h"

using namespace std;

char* err;
sqlite3* db;
int rc = 0;
string sql, query, display;
static int callback(void* NoUse, int argc, char** argv, char** azColNAme);

int main()
{
	//createDB();
	database empdb;
	empdb.createEmpTable();
	int id;
	string nm, desgn, dob, gen, ps;
	/*
	id = 200;
	nm = "Binni K"; desgn = "Employee"; dob = "2000/10/31"; gen = "F";
	ps = "bin01";
	*/
	cout << "\nCREATE NEW RECORD:=\n";
	cout << "Enter Id: ";
	cin >> id;
	cout << "Enter name: ";
	cin >> nm;
	cout << "Enter Designation: ";
	cin >> desgn;
	cout << "Enter dob(YYYY/MM/DD): ";
	cin >> dob;
	cout << "Enter gender(M/F): ";
	cin >> gen;
	cout << "Enter password: ";
	cin >> ps;

	empdb.insertEmpData(id, nm, desgn, dob, gen, ps);

	cout << "\nUPDATE RECORD:=\n";
	cout << "Enter ID of the record to be update: ";
	cin >> id;
	cout << "Enter updated details-\nName: ";
	cin >> nm;
	cout << "Designation: ";
	cin >> desgn;
	cout << "DOB(YYYY/MM/DD): ";
	cin >> dob;
	empdb.updateEmpData(id, nm, desgn, dob);
	
	cout << "\nDELETE RECORD:- ";
	cout << "Enter Id: ";
	cin >> id;
	empdb.deleteEmpData(id);
	return 0;
}

database::database()
{
	open_db();
}
database::~database()
{
	close_db();
}
int database::open_db() 
{
	int status = sqlite3_open("BANK.db", &db);
	if (status) {
		cout<<"Can't open database: \n"<<sqlite3_errmsg(db);
		return 0;
	}
	else {
		cout<<"Opened database successfully!\n";
	}
	return status;
}
//function to create employee table in database
int database::createEmpTable()
{
	//SQL statement to create table in database if not exists
	sql = "CREATE TABLE IF NOT EXISTS employee("
		"EmployeeID INT PRIMARY KEY,"
		"Name VARCHAR(60) NOT NULL,"
		"Designation VARCHAR(60),"
		"DoB DATE,"
		"Gender CHAR NOT NULL,"
		"emp_password VARCHAR(20) NOT NULL);";

	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);		//executing SQL statement
	if (rc != SQLITE_OK) {
		cout << "Error: " << err << endl;
		return 0;
	}
	else
	{
		cout << "Table EMPLOYEE created!";
		return 1;
	}
}

//function to insert data into employee database
int database::insertEmpData(int empid,string name,string desig,string dob,string gender,string pass)
{
	string com = "','";
	string id = to_string(empid);
	string s = "INSERT INTO employee VALUES('" + id + com + name + com + desig + com + dob + com + gender + com + pass + "' );";
	rc = sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if (rc != SQLITE_OK) {
		cout << "Insert Error: " << err << endl;
		return 0;
	}
	else {
		cout << "-> Record created successfully!" << endl;
		return 1;
	}
}
//fnction to update data of employees
int database::updateEmpData(int empid, std::string name, std::string desig, std::string dob)
{
	string id = to_string(empid);
	sql = "UPDATE employee SET Name='" + name + "',Designation='" + desig + "',DoB='" + dob + "' WHERE EmployeeID='" + id + "';";
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cout << "Update Error: " << err << endl;
		return 0;
	}
	else {
		cout << "-> Record updated successfully!" << endl;
		return 1;
	}
}
//function to display employee data
void database::getEmpData(int empid)
{
	string id = to_string(empid);
	sql = "SELECT * FROM employee WHERE EmployeeID="+id+";";
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
}
//function to delete employee data
int database::deleteEmpData(int empid)
{
	string id = to_string(empid);
	sql = "DELETE FROM employee WHERE EmployeeID='" + id + "';";
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cout << "Delete Error: " << err << endl;
		return 0;
	}
	else {
		cout << "-> Record deleted successfully!" << endl;
		return 1;
	}
}
void database::createCustTable()
{
	//SQL statement to create table in database if not exists
	sql = "CREATE TABLE IF NOT EXISTS customer("
		"AccountNo INT PRIMARY KEY AUTO_INCREMENT=1000,"
		"Name VARCHAR(60) NOT NULL,"
		"Balance DOUBLE NOT NULL,"
		"DoB DATE,"
		"PhoneNo VARCHAR(60),"
		"Gender CHAR,"
		"emp_password VARCHAR(20) NOT NULL);";

	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);		//executing SQL statement
	if (rc != SQLITE_OK) {
		cout << "Error: " << err << endl;
		//return 0;
	}
	else
	{
		cout << "Table CUSTOMER created!";
		//return 1;
	}
}
void database::insertCustData(int acc_no, std::string name, float balance, std::string dob, std::string ph_no, std::string gender, std::string pass)
{
	string com = "','";
	string no = to_string(acc_no);
	string bal = to_string(balance);
	string s = "INSERT INTO customer VALUES('" + no + com + name + "'," + bal + ",'" + dob + com + ph_no + com + gender + com + pass + "' );";
	rc = sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if (rc != SQLITE_OK) {
		cout << "Insert Error: " << err << endl;
		//return 0;
	}
	else {
		cout << "-> Record inserted successfully!" << endl;
		//return 1;
	}
}
void database::updateCustData(int acc_no, std::string name, std::string dob, std::string ph_no)
{
	string ac_no = to_string(acc_no);
	sql = "UPDATE customer SET Name='" + name + "',DoB='" + dob + "',PhoneNo='" + ph_no + "' WHERE AccountNo='" + ac_no + "';";
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cout << "Update Error: " << err << endl;
		//return 0;
	}
	else {
		cout << "-> Record updated successfully!" << endl;
		//return 1;
	}
}
void database::getCustData(int acc_no)
{
	string ac_no = to_string(acc_no);
	sql = "SELECT * FROM customer WHERE AccountNo=" + ac_no + ";";
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
}
float database::getCustBalance(int acc_no)
{
	return 0.0f;
}
//Function to check if the balance is sufficient for withdrawal
int database::checkSufficientBalance(int acc_no,int amount)
{
	string ac_no = to_string(acc_no);
	string amt = to_string(amount);
	sql = "SELECT * FROM customer WHERE AccountNo='" + ac_no + "' AND " + amt + "<Balance;";
	rc=sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		return 0;
	}
	else {
		return 1;
	}
	return 0;
}

void database::updateCustBalance(int acc_no,float amount)
{
	float balance = getCustBalance(acc_no);
	amount = amount + balance;
	string amt = to_string(amount);
	string ac_no = to_string(acc_no);
	sql = "UPDATE customer SET Balance='" + amt + "' WHERE AccountNo='" + ac_no + "';";
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cout << "Update Error: " << err << endl;
		//return 0;
	}
	else {
		cout << "-> Balance updated successfully!" << endl;
		//return 1;
	}
}
void database::deleteCustData(int acc_no)
{
	string ac_no = to_string(acc_no);
	sql = "DELETE FROM customer WHERE AccountNo='" + ac_no + "';";
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cout << "Delete Error: " << err << endl;
		//return 0;
	}
	else {
		cout << "-> Record deleted successfully!" << endl;
		//return 1;
	}
}

//function to retrieve contents of the database
//used by getData() functions
static int callback(void* NoUse, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		//column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;
	return 0;
}
//argc:holds the number of results
//azColName:holds each column returned in array
//argv:holds each value in array

void database::close_db()
{
	sqlite3_close(db);
}

