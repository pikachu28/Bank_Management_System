#pragma once
#include<iostream>
#include<string>

class database
{
public:
	database(){
		open_db();
	}
	~database()
	{
		close_db();
	}
	int open_db();
	//int print_data(string s);
	//void create_db();
	void close_db();
	int createEmpTable();
	int insertEmpData(int empid, std::string name, std::string desig, std::string dob, std::string gender, std::string pass);
	int updateEmpData(int empid, std::string name, std::string desig, std::string dob);
	void getEmpData(int empid);
	int deleteEmpData(int empid);
	//void createTransactionTable();
	//void viewTransactionTable();
	void createCustTable();
	int insertCustData(int acc_no,std::string name,float balance,std::string dob,std::string ph_no,std::string gender,std::string pass);
	int updateCustData(int acc_no, std::string name, std::string dob, std::string ph_no);
	int getCustData(int acc_no);
	int deleteCustData(int acc_no);
	void TransactionTable(std::string acc_no);
	void createTransactionTable(std::string acc_no);
	bool viewTransactionDetails(std::string acc_no);
	//void delete_db();
	//void check(int);
	
};

