#include<iostream>
#include "employee.h"
#include "db.h"
#include "customer.h"

using namespace std;
int check;
database tempdb2;
Cust tempCust;


employee::employee(int id)
{
    emp_id = id;
}

void employee::NewEmployeeReg()
{
    system("CLS");
    cout << "\n\t\t\t-NEW EMPLOYEE REGISTRATION- \n";

    cout << "\n\t\t\tEnter the Employee No. : ";
    cin >> emp_id;
    cout << "\n\t\t\tEnter password : ";
    cin >> empPassword;
    cout << "\n\t\t\tName of the Employee : ";
    cin.ignore();
    cin >> empName;
    cout << "\n\t\t\tEnter Designation : ";
    cin >> desig;
    cout << "\n\t\t\tGender : ";
    cin >> gender;
    gender = toupper(gender);
    cout << "Enter Date of Birth (YYYY/MM/DD): ";
    cin >> DOB;
    check = tempdb2.insertEmpData(emp_id, empName, desig, DOB, gender, empPassword);
    if (check)
        cout << "\n\n\t\t\tRegistration Successful!";
    else
        cout << "\n\t\tError in registration! We apologise..";

}

void employee::viewEmployee()
{
    system("CLS");
    int num;
    cout << "\n\t\t\t-VIEW EMPLOYEE DETAILS- \n";

    cout << "\n\t\t\tEnter the Employee ID : ";
    cin >> num;
    cout << "\n\t\t\t DETAILS:-\n";
    tempdb2.getEmpData(num);
}

void employee::VeiwAllAccounts()
{
    system("CLS");
    cout << "\n\t\t\t-VIEW ALL CUSTOMER ACCOUNTS- \n";
    tempdb2.viewAllCust();
}

void employee::SearchCustomer()
{
    system("CLS");
    int num;
    cout << "\n\t\t\t-VIEW CUSTOMER ACCOUNT- \n";

    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> num;
    cout << "\n\t\t\tACCOUNT DETAILS:-\n";
    tempdb2.getCustData(num);
}

void employee::updateDetails()
{
    system("CLS");
    cout << "\n\t\t\t-UPDATE EMPLOYEE DETAILS- \n";
    cout << "\n\t\t\tENTER THE UPATED DATA:- ";
    cout << "\n\t\t\tEnter the Employee No. : ";
    cin >> emp_id;
    cout << "\n\t\t\tName of the Employee : ";
    cin.ignore();
    cin >> empName;
    cout << "\n\t\t\tEnter Designation : ";
    cin >> desig;
    cout << "\n\t\t\tGender : ";
    cin >> gender;
    gender = toupper(gender);
    cout << "Enter Date of Birth (YYYY/MM/DD): ";
    cin >> DOB;
    check = tempdb2.updateEmpData(emp_id, empName, desig, DOB);
    if (check)
        cout << "\n\n\t\t\tDetails Updated!";
    else
        cout << "\n\t\tError in updating details! We are sorry..";

}

void employee::updateCust_Details()
{
    int num;
    cout << "\n\t\t\t-UPDATE CUSTOMER ACCOUNT- \n";
    tempCust.updateDetails();

}

void employee::deleteCustAccount()
{
    int num;
    cout << "\n\t\t\t-DELETE CUSTOMER ACCOUNT- \n";

    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> num;
    check = tempdb2.deleteCustData(num);
    if (check)
        cout << "\n\t\t\tThe Account has been deleted..!";
    else
        cout << "Error in deleting..!";
}

void employee::deleteEmp()
{
    int num;
    cout << "\n\t\t\t-DELETE EMPLOYEE RECORD- \n";

    cout << "\n\t\t\tEnter the Employee ID : ";
    cin >> num;
    check = tempdb2.deleteEmpData(num);
    if (check)
        cout << "\n\t\t\tThe Record has been deleted..!";
    else
        cout << "Error in deleting..!";
}
