//Customer class
#pragma once
#include<iostream>

class Cust
{
private:
	std::string name = "";
	std::string pass = "";
	double balance = 0.0;
	long acc_no;
	std::string mobile = "";
	std::string DOB = "";
	std::string gender = "";
public:
	Cust(long n);
	//~Cust();
	//int getCust_id();
	//double getBalance();
	//long getAcc_no();
	void NewAccount();
	void updateDetails();
	void viewDetails();
	void deposit();
	void withdraw();
	void deleteAcc();
};
