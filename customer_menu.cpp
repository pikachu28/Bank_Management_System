#include<iostream>
#include<string>

using namespace std;
inline void clrscr()
{
  system("cls");
}


class Cust {
private:
    int cust_id;
    std::string cust_name = "";
    std::string cust_pass = "";
    std::string cust_add = "";
    std::string cust_email = "";
    double balance = 0.0;
    long acc_no;
    std::string DOB = "";
    void setBalance(double b);

public:
    /*
     Cust();
     Cust(long acc_no);
     Cust(std::string name, std::string password, long acc_no);
     ~Cust();
     int getCust_id();
     double getBalance();
     long getAcc_no();
     std::string getName();
     void setName(std::string s);
     void Deposit(double sum);
     void Withdraw(double sum);
     */
    void newAccountCUST();
    void cust_getRecord();
    void delete_acc();
    void deposit_withdraw();
    void cust_updateDetails();
};
void Cust::newAccountCUST()
{
        cout << "\n\n\t CUSTOMER DETAILS";
        cout << "\n\t Enter Customer Name: ";
        cin >> cust_name;
        cout << "\n\t Enter Customer Email ID: ";
        cin >> cust_email;
        cout << "\n\t Enter Customer Address: ";
        cin >> cust_add;
        cout << "\n\t Enter Gender (M/F): ";
        cin >> cust_add;


        //make an account and show the details.
        cout << "\n\t Your Account has been created Successfully!";

        cout << "\n\n\t Your default Password is 0";
        cout << "\n\t CUSTOMER BANK BALANCE = 0";
        //bank balance can be viewed on the table only - the default password line can be removed

        cout << "\n\n\n\t 1. TO DEPOSIT MONEY";
        cout << "\n\t 2. TO CHANGE PASSWORD";
        cout << "\n\t Please Enter Your Choice (1 OR 2) ";

        int a1;
        cin >> a1;

        switch (a1) {
            case 1: clrscr();
                     deposit_withdraw();
                     break;
            case 2: clrscr();
                     cust_updateDetails();
                     //change details
                     break;
            case 3: break;
        }

    }

    void Cust::cust_getRecord() {
        // cout << "\n\n\tCUSTOMER DETAILS";
        // cout << "\n\t Enter Customer Name:";
        // cin >> cust_name;
        // cout << "\n\t Enter Customer Id:";
        // cin >> acc_no;
        // cout << "\n\t Enter Password";
        // cin >> cust_pass;

        //open the details table
        //can also have CUSTOMER BANK BALANCE"

        cout << endl;
        cout << "\n\t 1. TO UPDATE YOUR DETAILS";
        cout << "\n\t 2. TO DEPOSIT OR WITHDRAW MONEY";
        cout << "\n\t Please Enter Your Choice (1 OR 2) ";

        int b1;
        cin >> b1;

        switch (b1) {
        case 1: clrscr();
            cust_updateDetails();
            break;
        case 2: clrscr();
            deposit_withdraw();
            break;
        case 3: break;
        }
    }

    void Cust::cust_updateDetails() {
        // cout << "\n\t Enter Customer Name:";
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
    }

    void Cust::deposit_withdraw() {
        // cout << "\n\n\t Enter Customer Name:";
        // cin >> cust_name;
        // cout << "\n\n\t Enter Customer Id:";
        // cin >> acc_no;
        // cout << "\n\n\t Enter Password";
        // cin >> cust_pass;

        //show table

        cout << "\n\t 1. TO WITHDRAW";
        cout << "\n\t 2. TO DEPOSIT";
        cout << "\n\t Please Enter Your Choice (1 OR 2) ";

        int b1, amount;
        cin >> b1;

        switch (b1) {
                case 1: 
                cout << "\n\t Enter the amount you want to withdraw: ";
                cin>>amount;
                //make changes in the account transaction section
                //amount is declared locally - change it to your class
                break;
                case 2:
                cout << "\n\t Enter the amount you want to deposit: ";
                cin>>amount;
                //make changes in the account transaction section
                //amount is declared locally - change it to your class
                break;
                case 3: break;
        }
    }

    void Cust::delete_acc() {
        // cout << "\n\n\n\tCUSTOMER DETAILS";
        // cout << "\n\t Enter Customer Name:";
        // cin >> cust_name;
        // cout << "\n\n\t Enter Customer Id:";
        // cin >> acc_no;
        // cout << "\n\n\t Enter Password";
        // cin >> cust_pass;

        //show the account details.

        cout << "\n\t IF YOU WISH TO DELETE THE ACCOUNT PRESS 1";
        cout << "\n\t ELSE PRESS 2";
        cout << "\n\t Please Enter Your Choice (1 OR 2) ";

        int d1;
        cin >> d1;

        switch (d1) {
                case 1: clrscr();
                cout << "\n\t Your account has been successfully deleted";
                //delete the account from the db
                break;
                case 2: clrscr();
                //go to the customer menu
                break;
        }
}

int main(){
   int key;
   cout << "\n\n\t CUSTOMER MENU";
   cout << "\n\t 1.MAKE A NEW ACCOUNT";
   cout << "\n\t 2.DISPLAY YOUR DETAILS";
   cout << "\n\t 3.UPDATE YOUR DETAILS";
   cout << "\n\t 4.DEPOSIT OR WITHDRAW MONEY";
   cout << "\n\t 5.DELETE ACCOUNT";
   cout << "\n\t Please Enter Your Choice (1-5) ";
   cin >> key;
   Cust c1;
   switch (key) {
        case 1: clrscr();
                c1.newAccountCUST();
                break;
        case 2: c1.cust_getRecord();
                break;
        case 3: c1.cust_updateDetails();
                break;
        case 4: c1.deposit_withdraw();
                break;
        case 5: c1.delete_acc();
                break;
        case 6: break;
   }
}
