#include<iostream>
#include<string>
#include "customer.h"
#include "db.h"

using namespace std;
inline void clrscr()
{
  system("cls");
}
database tempdb;
static int check = 0;

void Cust::NewAccount()
{
    system("CLS");
    cout << "\n\t\t\t-NEW ACCOUNT REGISTRATION- \n";

    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acc_no;
    cout << "\n\t\t\tEnter password : ";
    cin >> pass;
    cout << "\n\t\t\tName of the Account holder : ";
    cin.ignore();
    cin >> name;
    cout << "\n\t\t\tGender : ";
    cin >> gender;
    cout << "\n\t\t\tMobile No. : ";
    cin >> mobile;
    cout << "\n\t\t\tDate of Birth (YYYY/MM/DD): ";
    cin >> DOB;
    cout << "\n\t\t\tEnter The Initial Balance : ";
    cin >> balance;
    check = tempdb.insertCustData(acc_no, name, balance, DOB, mobile, gender, pass);
    if (check)
        cout << "\n\n\t\t\tYour Account has been created Successfully!";
    else
        cout << "\n\t\tError in creating a new account. We apologise..";
}

void Cust::updateDetails() 
{
    system("CLS");
    cout << "\n\t\t\t-UPDATE DETAILS- \n";

    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acc_no;
    cout << "\n\t\t\tENTER THE UPDATED DETAILS:-";
    cout << "\n\t\t\tName of the Account holder : ";
    cin.ignore();
    cin >> name;
    cout << "\n\t\t\tGender : ";
    cin >> gender;
    cout << "\n\t\t\tMobile No. : ";
    cin >> mobile;
    cout << "\n\t\t\tDate of Birth (YYYY/MM/DD): ";
    cin >> DOB;
    check = tempdb.updateCustData(acc_no, name, DOB, mobile);
    if (check)
        cout << "\n\n\t\t\tDetails have been updated!";
    else
        cout << "\n\t\tError in updating details. We apologise..";

        /* cout << "\n\t Enter Customer Name:";
        // cin >> cust_name;
        // cout << "\n\t Enter Customer Id:";
        // cin >> acc_no;
        // cout << "\n\t Enter Password";
        // cin >> cust_pass;

        cout << "\n\n\t CUSTOMER DETAILS";
        //cout the table of your details.

        cout << "\n\t UPDATE YOU DETAILS";
        cout << "\n\t 1. To change your Address";
        cout << "\n\t 2. To change your Email ID";
        cout << "\n\t 3. To change your Designation";
        cout << "\n\t 4. To change your Password";
        // cout << "\n\t5. To change your Phone number";
        cout << "\n\t Please Enter Your Choice (1-4)";
        cout << endl;
        int c1;
        cin >> c1;

        switch (c1) {
        case 1: clrscr();
            cout << "\n\t Enter New Address: ";
            cin>>cust_add;
            break;
        case 2: clrscr();
            cout << "\n\t Enter New Email ID: ";
            cin>>cust_email;
            break;
        case 3: clrscr();
            cout << "\n\t Your designation has been updated! ";
            //here we can delete the account and make an employee account with same data
            //two dbms commands to be included
            //3. is not working on my laptop 
            break;
        case 4: clrscr();
            cout << "\n\t Enter New Password: ";
            cin>>cust_pass;
            break;
        // case 5: clrscr();
        //     cout << "Enter New Phone number: ";
        //     break;
        case 5: break;
        }
        cout << "\n\n\t UPDATED CUSTOMER DETAILS";
        //cout the table of your details.
        */
 }

void Cust::viewDetails()
{
    system("CLS");
    cout << "\n\t\t\t-ACCOUNT DETAILS- \n";
    tempdb.getCustData(acc_no);
}

void Cust::deposit()
{
    system("CLS");
    float amt;
    cout << "\n\t\t\t-DEPOSIT MONEY- \n";
    cout << "\n\t\t\tEnter the Amount : ";
    cin >> amt;
    check = tempdb.updateCustBalance(acc_no, amt);
    if (check)
        cout << "\n\t\t\tThe money has been deposited..!";
    else
        cout << "Error!";
    //cout << "The updated balance is " << getBalanace();
}

void Cust::withdraw()
{
    float amt;
    cout << "\n\t\t\t-WITHDRAW MONEY- \n";
    cout << "\n\t\t\tEnter the Amount : ";
    cin >> amt;
    if (tempdb.checkSufficientBalance(acc_no, amt)) {
        amt = amt * (-1);
        check = tempdb.updateCustBalance(acc_no, amt);
        if (check)
            cout << "\n\t\t\tWithdrawal Successful!";
        else
            cout << "Error!";
    }
    else
        cout << "Balance Insifficient!!";

    /*balance = tempdb.getCustBalance(acc_no);
    cout<<"The updated balance is : "<<balance;*/
    
}

void Cust::deleteAcc()
{
    int ch;
    cout << "\n\t\t\t-DELETE ACCOUNT- \n";
    cout << "\n\t\t\tYou are about to delete the account! ";
    cout << "\n\t\t\tPress 1 to continue..  ";
    cin >> ch;
    if (ch == 1){
        check = tempdb.deleteCustData(acc_no);
        if (check)
            cout << "\n\t\t\tThe Account has been deleted..!";
        else
            cout << "Error in deleting..!";
    }
}
