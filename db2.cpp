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
	cout << "Enter passwprd: ";
	cin >> ps;

	empdb.insertEmpData(id, nm, desgn, dob, gen, ps);

	cout << "\n\t---All Employees Record---";
	empdb.printEmpData();
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
	int status = sqlite3_open("EMPLOYEE.db", &db);
	if (status) {
		cout<<"Can't open database: \n"<<sqlite3_errmsg(db);
		return 0;
	}
	else {
		cout<<"Opened database successfully!\n";
	}
	return status;
}

void database::createEmpTable()
{
	//SQL statement to create table in database if not exists
	sql = "CREATE TABLE IF NOT EXISTS employee("
		"emp_id INT PRIMARY KEY,"
		"emp_name VARCHAR(60) NOT NULL,"
		"emp_desig VARCHAR(60),"
		"empDOB DATE,"
		"gender CHAR NOT NULL,"
		"emp_password VARCHAR(20) NOT NULL);";

	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);		//executing SQL statement
	if (rc != SQLITE_OK)
		cout << "Error: " << err << endl;
	else
	{
		cout << "Table EMPLOYEE created!";
	}
}
//function to insert data into employee database
void database::insertEmpData(int empid,string name,string desig,string dob,string gender,string pass)
{
	//SQL query to insert values into the table
	query = "INSERT INTO employee VALUES ('001','Akash Verma','Manager','1990/10/21', 'M', 'pass01');"
		"INSERT INTO employee VALUES ('002','Vivek Sharma','Manager', '1993/04/20', 'M', 'pass02');"
		"INSERT INTO employee VALUES ('004','Nidhi Gupta','Manager', '1996/19/31', 'F', 'pass04');"
		"INSERT INTO employee VALUES ('101','Sanya Mishra','Employee', '1989/08/16', 'F', 'pass101');"
		"INSERT INTO employee VALUES ('103','Sahil Rustagi','Employee', '1992/01/22', 'M', 'pass103');";
	
	//To execute insert SQL query
	//rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);

	string com = "','";
	string id = to_string(empid);
	string s = "INSERT INTO employee VALUES('" + id + com + name + com + desig + com + dob + com + gender + com + pass + "' );";
	rc = sqlite3_exec(db, s.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK)
		cout << "Insert Error: " << err << endl;
	else
		cout << "-> Record created successfully!" << endl;
}

void database::printEmpData()
{
	string sql = "SELECT * FROM employee;";
	cout << endl << sql << endl;
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
}
//function to retrieve contents of the database
//used by selectData() function
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
