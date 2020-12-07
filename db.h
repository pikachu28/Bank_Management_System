#pragma once
#include<iostream>
#include<string>

//definition of database utilisation functions

class database
{
public:
	database();
	~database();
	int open_db();
	//int print_data(string s);
	//void create_db();
	void close_db();
	void createEmpTable();
	//void createCustTable();
	//void createTransactionTable();
	//void check(int);
	void insertEmpData(int empid, std::string name, std::string desig, std::string dob, std::string gender, std::string pass);
	void printEmpData();

};
