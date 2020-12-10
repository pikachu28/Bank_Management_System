#include <iostream>
#include<sqlite3.h>
#include"sqlite.h"
#include"customer.h"
#include"db.h"
#include"employee.h"

using namespace std;

database db1;
Cust cust1;
employee emp1;

void employee_menu()
{
	int ch;
	system("CLS");
	do {
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";

		cout << "\t\t\t\t    ::EMPLOYEE MENU::\n";
		cout << "\n\t\t\t\t1. NEW RECORD";
		cout << "\n\t\t\t\t2. UPDATE DETAILS";
		cout << "\n\t\t\t\t3. VIEW CUSTOMER ACCOUNTS";
		cout << "\n\t\t\t\t4. MODIFY AN ACCOUNT";
		cout << "\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout << "\n\t\t\t\t7. BACK TO MAIN MENU";
		cout << "\n\n\t\t\tEnter your option(1-8)=> ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			emp1.NewEmployeeReg();
			break;
		case 2:
			emp1.updateDetails();
			break;
		case 3:
			emp1.SearchCustomer();
			break;
		case 4:
			emp1.updateCust_Details();
			break;
		case 5:
			emp1.VeiwAllAccounts();
			break;
		case 6:
			emp1.deleteCustAccount();
			break;
		}
	} while (ch < 7);
}

void cust_menu()
{
	int ch;
	do {
		system("CLS");
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";

		cout << "\t\t\t\t    ::CUSTOMER MENU::\n";
		cout << "\n\t\t\t\t1. NEW ACCOUNT";
		cout << "\n\t\t\t\t2. UPDATE DETAILS";
		cout << "\n\t\t\t\t3. DEPOSIT";
		cout << "\n\t\t\t\t4. WITHDRAW";
		cout << "\n\t\t\t\t5. DELETE ACCOUNT";
		cout << "\n\t\t\t\t6. BACK TO MAIN MENU";
		cout << "\n\n\t\t\tEnter your option(1-6)=> ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cust1.NewAccount();
			break;
		case 2:
			cust1.updateDetails();
			break;
		case 3:
			cust1.deposit();
			break;
		case 4:
			cust1.withdraw();
			break;
		case 5:
			cust1.deleteAcc();
			break;
		}
	} while (ch < 6);
 }
void admin_menu()
{
	int ch;
	do {
		system("CLS");
		cout << "\t\t\t\t    ::ADMIN MENU::\n";
		cout << "\n\t\t\t\t1. INSERT NEW EMPLOYEE RECORD";
		cout << "\n\t\t\t\t2. UPDATE DETAILS OF AN EMPLOYEE";
		cout << "\n\t\t\t\t3. DELETE EMPLOYEE RECORD";
		cout << "\n\t\t\t\t4. VIEW EMPLOYEE DATA";
		cout << "\n\t\t\t\t5. BACK TO MAIN MENU";
		cout << "\n\n\t\t\tEnter your option(1-5)=> ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			//function to insert/register a employee record
			emp1.NewEmployeeReg();
			break;
		case 2:
			//function to update employee record
			emp1.updateDetails();
			break;
		case 3:
			//function to delete employee record
			emp1.deleteEmp();
			break;
		case 4:
			// Funtion to view the employee data
			emp1.viewEmployee();
			break;
		default:cout << "\a";
		}
	} while (ch < 4);

}

int main()
{
	

	int ch,c;
	do
	{
		system("CLS");
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";

		cout << "\t\t\t\t    ::MAIN MENU::\n";
		cout << "\n\t\t\t\t1. ADMIN";
		cout << "\n\t\t\t\t2. EMPLOYEE";
		cout << "\n\t\t\t\t3. CUSTOMER";
		cout << "\n\t\t\t\t4. EXIT";
		cout << "\n\n\t\t\tSelect Your Option (1-4): ";
		cin >> ch;

		switch (ch)
		{
		case 1:
				system("CLS");
				cout << "\n\n\t\t\tGoing To Admin Login....";
				if(adminLogin())
				{
					admin_menu();
				}
				break;
		case 2:
				system("CLS");
				//employee_menu();
				cout << "\n\t\t\t\t1. EMPLOYEE LOGIN";
				cout << "\n\t\t\t\t2. NEW EMPLOYEE REGISTRAION";
				cout << "\n\n\t\t\tEnter your choice=> ";
				cin >> c;
				if (c == 1)
				{
					if (empLogin())
					{
						cout << "\n\n\t\t\tGo To Employee Login";
						employee_menu();
					}
				}
				else if(c==2)
					emp1.NewEmployeeReg();
				break;
		case 3:
				system("CLS");
				cout << "\n\t\t\t\t1. CUSTOMER LOGIN (Existing Customer)";
				cout << "\n\t\t\t\t2. NEW ACCOUNT REGISTRAION";
				cout << "\n\n\t\t\tEnter your choice=> ";
				cin >> c;
				if (c == 1)
				{
					if (empLogin())
					{
						cout << "\n\n\t\t\tGo To Customer Login";
						employee_menu();
					}
				}
				else if (c == 2)
					emp1.NewEmployeeReg();
				break;
		case 4:
				system("CLS");
				cout << "\n\n\t\t\t-Developed by-";
				cout << "\n\n\t\t\tMitali Larioa(020)";
				cout << "\n\n\t\t\tBinwant Kaur(030)";
				cout << "\n\n\t\t\tAnagha Jain(037)";
				cout << "\n\n\t\t\tAnjali Singh(038)";
				cout << "\n\n\t\t\tAstha Khatana(040)";
				break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();

		if (ch == 4)
			break;
	} while (ch < 5);
	return 0;
}
