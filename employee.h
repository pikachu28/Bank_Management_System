#pragma once
#include"customer.h"

class employee
{
private:
	int emp_id;
	std::string empName = "";
	std::string empPassword = "";
	std::string desig = "";
	std::string DOB = "";
	std::string gender = "";

public:
	employee(){}
	//employee(int id);
	void NewEmployeeReg();//to register new employees
	void viewEmployee();
	void VeiwAllAccounts(); // to view all user accounts from the db.-*(cust_name and account_no only.)*
	void SearchCustomer(); //to search for a customer details using cust_id or acc_no
	void updateDetails(); //to update name/phone no./DOB/Designation-(not password) of self
	void updateCust_Details(); //to update customer details- **for managers only**
	void deleteCustAccount();
	void deleteEmp();
};
