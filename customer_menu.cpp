include<iostream>
#include<string>

class Cust{
private:
    int cust_id;
    std::string cus_name="";
    std::string cus_pass="";
    std::string cus_add="";
    std::string cus_email="";
    double balance=0.0;
    long acc_no;
    std::string cus_mobile="";
    std::string DOB="";
    void setBalance(double b);

public:
    Cust();
    Cust(long acc_no);
    Cust(std::string name,std::string password,long acc_no);
    ~Cust();
    int getCust_id();
    double getBalance();
    long getAcc_no();
    std::string getName();
    void setName(std::string s);
    void Deposit(double sum);
    void Withdraw(double sum);

    void getRecord(){
        cout<<"\n\n\n\tCUSTOMER DETAILS";
        cout<<"\n\n\t CUSTOMER NAME:";
        cout<<"\n\n\t CUSTOMER EMAIL ID:";
        cout<<"\n\n\t CUSTOMER ADDRESS";
        cout<<"\n\n\t CUSTOMER BANK BALANCE";
        cout<<"\n\n\t TO UPDATE YOUR DETAILS PRESS 1";
        cout<<"\n\n\t TO DEPOSIT OR WITHDRAW MONEY PRESS 2";
        cout<<"\n\n\tPlease Enter Your Choice (1 OR 2) ";
    }
    void NewAccountCUST(){
        cout<<"\n\n\n\tCUSTOMER DETAILS";
        cout<<"\n\n\t CUSTOMER NAME:";
        cout<<"\n\n\t CUSTOMER EMAIL ID:";
        cout<<"\n\n\t CUSTOMER ADDRESS";
        cout<<"\n\n\t CUSTOMER PASSWORD";
        cout<<"\n\n\t CUSTOMER BANK BALANCE";
        cout<<"\n\n\t TO DEPOSIT MONEY PRESS 1";

    }

};
    int a1;
    cout<<"\n\n\n\tCUSTOMER MENU";
    cout<<"\n\n\t1.ENTER YOUR DETAILS";
    cout<<"\n\n\t2.DISPLAY YOUR DETAILS";
    cout<<"\n\n\t3.UPDATE YOUR DETAILS";
    cout<<"\n\n\t4.DEPOSIT OR WITHDRAW MONEY";
    cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
    switch(a1)
        {
            case '1': clrscr();
                    NewAccountCUST;
                    break;
            case '2': getRecord();
                    break;
            case '3': updateDetails();
                    break;
            case '3': deposit_withdraw();
            break;
            case '5': break;
            default:customer_menu();
        }
