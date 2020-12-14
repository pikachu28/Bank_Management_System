#include<iostream>
#include"sqlite3.h"
#include"Transaction.h"

using namespace std;

char* err;
sqlite3* db;
int rc = 0;
std::string sql, query, display, data;
static int callback(void* NoUse, int argc, char** argv, char** azColNAme);

database::database()
{
	open_db();
	create_db();
}
database::~database()
{
	close_db();
}
void database::open_db()
{
	int status = sqlite3_open("BANK.db", &db);
	if (status) {
		cout << "Can't open database: \n" << sqlite3_errmsg(db);
	}
	else {
		cout << "Opened database successfully!\n";
	}
}
void database::create_db()
{
	//createEmpTable();
	//createCustTable();
	createTransactionTable();
}
void database::close_db()
{
	sqlite3_close(db);
}

// here acc_no refers to the acc_no of the customer for whom the function transaction has been called
void database::TransTable()
{
	sql = "CREATE TABLE IF NOT EXISTS "+ acc_no " ("
		"DATE TIMESTAMP PRIMARY KEY,"
		"CURRENT_BALANCE NUMERIC(30) NOT NULL,"
		"AMOUNT_TRANSFERED NUMERIC(30) NOT NULL);";
	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);		//executing SQL statement
	if (rc != SQLITE_OK) {
		cout << "Error: " << err << endl;
	}
	else{
		cout << "Table TRANSACTION exits!";
	}
	//string s = "INSERT INTO acc_no VALUES('111','Binwant','pass111');"
	//	"INSERT INTO acc_no VALUES('101','Anjali','pass101');";
	rc = sqlite3_exec(db, s.c_str(), NULL, 0, &err);
	if (rc != SQLITE_OK) {
		cout << "Insert Error: " << err << endl;
		//return 0;
	}
	else {
		cout << "-> Transaction Record created successfully!" << endl;
		//return 1;
	}
}
