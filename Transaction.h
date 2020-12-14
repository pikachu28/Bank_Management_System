#pragma once
#include<iostream>
#include<string>
#include"sqlite3.h"

using namespace std;

class database
{
public:
	database();
	~database();
	void open_db();
	void create_db();
	void close_db();

	void TransactionTable();
    void  createTransactionTable();
	//void viewTransactionTable();
	//void delete_db();//To delete the complete database.
};