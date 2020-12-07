include<iostream>
#include<string>

class Cust{
        private:
        int cust_id;
        std::string cust_name="";
        std::string cust_pass="";
        std::string cust_add="";
        std::string cust_email="";
        double balance=0.0;
        long acc_no;
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

        void newAccountCUST(){

                cout<<"\n\n\n\tCUSTOMER DETAILS";
                cout<<"\n\n\t Enter Customer Name:";
                cin>>cust_name;
                cout<<"\n\n\t Enter Customer Email ID:";
                cin>>cust_email;
                cout<<"\n\n\t Enter Customer Address";
                cin>>cust_add;

                //make an account and show the details.
                cout<<"\n\n\t Your Account has been created Successfully!";

                cout<<"\n\n\t Your default Password is 0";
                cout<<"\n\n\t CUSTOMER BANK BALANCE = 0;"
                //bank balance can be viewed on the table only - the default password line can be removed

                cout<<"\n\n\t TO DEPOSIT MONEY PRESS 1";
                cout<<"\n\n\t TO CHANGE PASSWORD PRESS 2";
                
        }

        void cust_getRecord(){
                cout<<"\n\n\n\tCUSTOMER DETAILS";
                cout<<"\n\n\t Enter Customer Name:";
                cin>>name;
                cout<<"\n\n\t Enter Customer Id:";
                cin>>acc_no;
                cout<<"\n\n\t Enter Customer Address";
                cin>>cust_add;
                cout<<endl<<endl;

                //open the details table
                //can also have CUSTOMER BANK BALANCE";

                cout<<endl;                
                cout<<"\n\n\t TO UPDATE YOUR DETAILS PRESS 1";
                cout<<"\n\n\t TO DEPOSIT OR WITHDRAW MONEY PRESS 2";
                cout<<"\n\n\tPlease Enter Your Choice (1 OR 2) ";

                switch(a1){
                        case '1': clrscr();
                                cust_updateDetails();
                                break;
                        case '2': clrscr();
                                deposit_withdraw();
                                break;
                        case '3': break;
                        default: //go to home page
                }
        }

        void cust_updateDetails(){
                cout<<"\n\n\t1.Enter your name";
                cout<<"\n\n\t2.Enter your account number";
                cout<<"\n\n\t2.Enter your DOB";
                cout<<endl;

                //cout the table of your details.
                cout<<"\n\n\n\tCUSTOMER DETAILS";

                cout<<"\n\n\t UPDATE YOU DETAILS";
                cout<<"\n\n\t1. To change your Address";
                cout<<"\n\n\t2. To change your Email ID";
                cout<<"\n\n\t3. To change your Phone number";
                cout<<"\n\n\t4. To change your Designation";
                cout<<"\n\n\tPlease Enter Your Choice (1-4)";
                cout<<endl;
                int a1;
                cin>>a1;

                switch(a1){
                        case '1': clrscr();
                                cout<<"Enter New Address: "
                                break;
                        case '2': clrscr();
                                cout<<"Enter New Email ID: "
                                break;
                        case '3': clrscr();
                                cout<<"Enter New Phone number: "
                                break;
                        case '4': clrscr();
                                //here we can delete the account and make an employee account with same data.
                        case '5': break;
                        default: //dont change anything
                }

                //cout the table of your details.
                cout<<"\n\n\n\tUPDATED CUSTOMER DETAILS";
        }

        void deposit_withdraw(){
                cout<<"Enter the amount you want to deposit or withdraw: "
                cout<<"NOTE: to withdraw - use - sign"
                //make changes in account details and display the updated table;

                //or we can make a switch case;
        }

        void delete_acc(){

                cout<<"\n\n\n\tCUSTOMER DETAILS";
                cout<<"\n\n\t Enter Customer Name:";
                cin>>cust_name;
                cout<<"\n\n\t Enter Customer Account Number:";
                cin>>acc_no;

                cout<<"\n\n\t IF YOU WISH TO DELETE THE ACCOUNT PRESS 1";
                cout<<"\n\n\t ELSE PRESS 2";

                int a1;
                cin>>a1;

                switch(a1){
                        case '1': clrscr();
                                //delete the account from the db
                                break;
                        case '2': clrscr();
                                //go to the customer menu
                                break;
                        default: //go to the customer menu
                }


                
        }

};

int a1;
cout<<"\n\n\n\tCUSTOMER MENU";
cout<<"\n\n\t1.MAKE A NEW ACCOUNT";
cout<<"\n\n\t2.DISPLAY YOUR DETAILS";
cout<<"\n\n\t3.UPDATE YOUR DETAILS";
cout<<"\n\n\t4.DEPOSIT OR WITHDRAW MONEY";
cout<<"\n\n\t5.DELETE ACCOUNT";
cout<<"\n\n\tPlease Enter Your Choice (1-5) ";
switch(a1){
        case '1': clrscr();
                newAccountCUST;
                break;
        case '2': cust_getRecord();
                break;
        case '3': cust_updateDetails();
                break;
        case '4': deposit_withdraw();
                break;
        case '5': delete_acc();
                break;
        case '6': break;
        default:customer_menu();
}
