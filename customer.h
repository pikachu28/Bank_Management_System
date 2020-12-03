//Customer class

#include<iostream>
#include<string>

class Cust
{
private:
	int cust_id;
	std::string custName="";
	std::string custPassword="";
	double balance=0.0;
	long acc_no;
	std::string phone_no="";
	std::string DOB="";
	void setBalance(double b);
public:
	Cust();
	Cust(long acc_no);
	Cust(std::string name,std::string password,long acc_no);

	~Cust();
	double getBalance();
	long getAcc_no();
	void NewAccount();
	std::string getName();
	void setName(std::string s);
	void Deposit(double sum);
	void Withdraw(double sum);
};
