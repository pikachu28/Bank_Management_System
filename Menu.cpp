#include <iostream>
#include<sqlite3.h>
#include "employee.h"
#include "customer.h"
#include "customerFunction.h"
using namespace std;

void adminMenu(){
	system("clear");
	int ch;
	cout << "\n\n\t\t\tGo To Admin Login";
	if(adminLogin()){
		do{	
		cout << "\t\t\t\t    ::ADMIN MENU::\n";
		cout << "\n\t\t\t\t1. INSERT EMPLOYEE'S RECORD";
		cout << "\n\t\t\t\t2. UPDATE DETAILS OF AN EMPLOYEE";
		cout << "\n\t\t\t\t3. DELETE EMPLOYEE RECORD";
		cout << "\n\t\t\t\t4. View Employee Data";
		cout << " \n\t\t\t\t5. Logout";
		cout << "\n\n\t\t\tEnter your option(1-5)=> ";
		cin >> ch;
	switch(ch)
	{
		case 1: 
			//function to insert/register a employee record
			empRegister();
			break;
		case 2: 
			//function to update employee record
			empUdate();
			break;
		case 3:
			//function to delete employee record
			empDel();
			break;
		case 4: 
			// Funtion to view the employee data
			empView();
			break;
			default:cout << "\a";
			}
		}while(ch<5);
	}

}

void employee_menu()
{
	system("clear");
	int ch;
	if(empLogin()){
		do{
	
	cout << "\n\n\t\t\t\t======================\n";
	cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout << "\n\t\t\t\t======================\n";

	cout << "\t\t\t\t    ::EMPLOYEE MENU::\n";
	cout << "\n\t\t\t\t1. NEW RECORD";
	cout << "\n\t\t\t\t2. UPDATE DETAILS";
	cout << "\n\t\t\t\t3. VIEW CUSTOMER ACCOUNTS";
	cout << "\n\t\t\t\t4. ALL ACCOUNT HOLDER LIST";
	cout << "\n\t\t\t\t5. CLOSE AN ACCOUNT";
	cout << "\n\t\t\t\t6. BACK TO MAIN MENU";
	cout << "\n\n\t\t\tEnter your option(1-6)=> ";
	cin >> ch;
	switch(ch){
		case 1:
			NewAccount();
			break;
		case 2:
			updateDetails();
			break;
		case 3:
			viewCustDetails();
			break;
		case 4:
			viewCustTable();
			break;
		case 5:
			closeAcc();
			break;
		default:cout << "\a";
	}
		}while(ch!=6);

	}

}

void cust_menu()
{
	int ch;
	system("clear");
	if(custLogin()){
			do{		
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t======================\n";

		cout << "\t\t\t\t    ::CUSTOMER MENU::\n";
		cout << "\n\t\t\t\t1. View ACCOUNT Details";
		cout << "\n\t\t\t\t2. UPDATE DETAILS";
		cout << "\n\t\t\t\t3. DEPOSIT";
		cout << "\n\t\t\t\t4. WITHDRAW";
		cout << "\n\t\t\t\t5. View Transaction Details";
		cout << "\n\t\t\t\t6. BACK TO MAIN MENU";
		cout << "\n\n\t\t\tEnter your option(1-6)=> ";
		
		cin >> ch;
		switch (ch) {
			case 1: 
				viewCustDetails();
				break;
			case 2: 
				updateDetails();
				break;
			case 3:
				depositInBal();
				break;
			case 4: 
				withdrawInBal();
				break;
			case 5:
				viewTransaction();
				break;
			case 6:
				break;
		}
	}while(ch!=6);
 }
}
int main()
{
	
	int ch;
	do
	{
		system("clear");
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
				adminMenu();
				break;
		case 2:
				employee_menu();
				break;
		case 3:
				system("clear");
				cout << "\n\n\t\t\tGo to Customer Login";
				cust_menu();
				break;
		case 4:
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
	} while (ch < 4);
	return 0;
}

