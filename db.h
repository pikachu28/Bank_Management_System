#pragma once
#include"emp.h"

//definition of database utilisation functions

class db
{

public:
	db();
	~db();
	int open_db(string);
	int print_data(string);
	void create_db();
	void close_db();
	void createEmpTable();
	//void createCustTable();
	//void createTransactionTable();
	void check(int);
	void insertEmpTable(int, string, string, string, string, string, string);
	void printEmpData();

};
