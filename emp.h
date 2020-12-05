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
   void VeiwAllAccounts(); // to view all user accounts from the db.-*(cust_name and account_no only.)*
   void SearchCustomer(); //to search for a customer details using cust_id or acc_no
   void updateDetails(); //to update name/phone no./DOB/Designation-(not password) of self
   void updateCust_Details(); //to update customer details- **for managers only**
};
