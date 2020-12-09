#include<iostream>
using namespace std;

int main(){
 
	int ch;
	system("CLS");
	cout << "\t\t\t\t    ::ADMIN MENU::\n";
	cout << "\n\t\t\t\t1. INSERT EMPLOYEE'S RECORD";
	cout << "\n\t\t\t\t2. UPDATE DETAILS OF AN EMPLOYEE";
	cout << "\n\t\t\t\t3. DELETE EMPLOYEE RECORD";
	cout << "\n\t\t\t\t4. BACK TO ADMIN MENU";
	cout << "\n\n\t\t\tEnter your option(1-4)=> ";
	cin >> ch;

	switch(ch)
            {
                case '1': 
                       //function to insert a employee record
                        break;
                case '2': //function to update employee record
                        break;
                case '3':
                       //function to delete employee record
                        break;
                case '4': admin_menu();
                        break;
                default:admin_menu();
            }


}