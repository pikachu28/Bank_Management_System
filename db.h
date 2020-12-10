#pragma once
#include<iostream>
#include<string>
#include<sqlite3.h>

using namespace std;

class database
{
public:
	database();
	~database();
	int open_db();
	void create_db();
	void close_db();
	void createEmpTable();
	int insertEmpData(int empid, std::string name, std::string desig, std::string dob, std::string gender, std::string pass);
	int updateEmpData(int empid, std::string name, std::string desig, std::string dob);
	void getEmpData(int empid);
	int deleteEmpData(int empid);
	void viewAllEmp();
	
	void createCustTable();
	int insertCustData(int acc_no,std::string name,float balance,std::string dob,std::string ph_no,std::string gender,std::string pass);
	int updateCustData(int acc_no, std::string name, std::string dob, std::string ph_no);
	void getCustData(int acc_no);
	float getCustBalance(int acc_no);
	int checkSufficientBalance(int acc_no,int amount);
	int updateCustBalance(int acc_no,float amt);
	int deleteCustData(int acc_no);
	void viewAllCust();
	//void createTransactionTable();
	//void viewTransactionTable();
	//void delete_db();//To delete the complete database.
};

