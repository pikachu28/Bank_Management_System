// BMSmain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void employee_menu()
{
	int ch;
	system("CLS");
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
}
void cust_menu()
{
	int ch;
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
	
	int key;
	switch (key) {
		case 1: clrscr();
			newAccountCUST();
			break;
		case 2: cust_updateDetails();
			break;
		case 3: deposit();
			break;
		case 4: withdraw();
			break;
		case 5: delete_acc();
			break;
		case 6: break;
	   }
}
int main()
{
	int ch;
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
				cout << "\n\n\t\t\tGo To Admin Login";
				break;
		case 2:
				system("CLS");
				cout << "\n\n\t\t\tGo To Employee Login";
				employee_menu();
				break;
		case 3:
				system("CLS");
				cout << "\n\n\t\t\tGo to Customer Login";
				cust_menu();
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
	} while (ch < 4);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
