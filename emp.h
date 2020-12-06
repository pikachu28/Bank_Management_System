//employee class

#include"customer.h"

class employee
{
private:
   int emp_id;
   std::string emp_name="";
   std::string empPassword="";
   std::string emp_add="";
   std::string emp_email="";
   std::string desig="";
   std::string DOB="";
   std::string emp_moblie="";

public:
   employee();
   employee(int emp_id,std::string empName,std::string desig);
   ~employee();

   void getRecord(){
       cout<<"\n\n Enter Employee id.";
      cin>>emp_id;
      cout<<"\n\n Enter Employee name.";
      cin>>emp_name;
      cout<<"\n\n Enter Password for your login account";
      cin>>empPassword;
      cout<<"\n\n Enter employee address";
      cin>>emp_add;
      cout<<"\n\n Enter employee email";
      cin>>emp_email;
      cout<<"\n\n Enter designation of the employee";
      cin>>desig;
      cout<<"Enter the date of birth";
      cin>>DOB;
      cout<<"Enter mobile no. of the employee";
      cin>>emp_moblie;
   }

   void printRecord(){
      cout<<"\n\n Employee id :"<<emp_id;
      cout<<"\n\n Employee Name :"<<emp_name;
      cout<<"\n\n Employee Address: "<<emp_add;
      cout<<"\n\n EMployee Email: "<<emp_email;
      cout<<"\n\n Employee Designation: "<<desig;
      cout<<"\n\n Date Of Birth: "<<DOB;
      cout<<"\n\n Phone: "<<emp_moblie;
   }


   void VeiwAllAccounts(); // to view all user accounts from the db.-*(cust_name and account_no only.)*

   void SearchCustomer(){
      cout<<"\n\n Enter the Customer id of the customer to be searched";
      cin>>cust_id;
      bool  Result_of_Search_query;
      if(Result_of_Search_query){
         function_to_print_data_of_customer;
      }
      else{
         cout<<"Sorry! Customer not found";
      }
   } //to search for a customer details using cust_id or acc_no

   void updateDetails(){
      cout<"\n\n Enter your new details";
      getRecord();
   } //to update name/phone no./DOB/Designation-(not password) of self

   void updateCust_Details(){
      int cust_id;
      cout<<"\n\n Enter the customer id whose record you want to update";
      cin>>cust_id;
      bool Result_of_Search_query_on_cust_id;
      if( Result_of_Search_query_on_cust_id){
         cout<<"\n\n Enter the new details of the customer";
         function_getdata_in_customerclass;
      }
      else{
         cout<<"Sorry! the customer with entered customer id is not in the records";
         return;
      }

   }; //to update customer details- **for managers only**
};
