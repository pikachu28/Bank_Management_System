#include <iostream>
#include <sqlite3.h>
#include "db.h"
using namespace std;

    int rc=0;
    string sql, query, display, data;
    sqlite3 *db;
    char* messageError;
    database db2;
    static int callback(void* data, int argc, char** argv, char ** azColName){
        //cout<<data<<endl;
        char* colName;
        char* colValueString;
        char* y;
        for(int i=0; i<argc; i++){
            colName = azColName[i];
            colValueString = argv[i];
            if(colValueString==0){
                y = NULL;
            }
            else{
                y = colValueString;
            }
            cout<<colName<<"="<<colValueString;
        }
        cout<<endl;
        return 0;
    }


    bool empLogin(){
        string password, id;
        cout<<"Enter your id";
        cin>>id;
        cout<<"Enter password";
        cin>>password;
        data = "Select *FROM employee WHERE EmployeeID='"+ id +"' and emp_password='"+ password +"'";
        rc = sqlite3_exec(db, data.c_str(), callback, NULL, NULL);
        if(rc != SQLITE_OK){
            cout<<"You are not an authenticated user"<<endl;
            sqlite3_free(messageError);
            return false;
            }
            else{
                    //write whatever function u wnat to perform in this block after login
                string query = "SELECT  *FROM employee WHERE EmployeeID='"+ id +"'";
                cout<<"Done...you can access your information"<<endl;
                    //sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
            return true;
        }
        }

    bool adminLogin(){
        string password;
        string id;
        cout<<"Enter your id";
        cin>>id;
        cout<<"Enter your password";
        cin>>password;
        data = "Select *FROM Administrator WHERE AdminId='"+ id +"' and Password='"+ password +"'";
        rc = sqlite3_exec(db, data.c_str(), callback, NULL, NULL);
        if(rc != SQLITE_OK){
            cout<<"You are not an admin"<<endl;
            sqlite3_free(messageError);
            return false;
        }
        else{
            cout<<"Welcome"<<endl;
            return true;
        }

    }

    void empRegister(){
        string  Name, Designation , DOB, Gender, emp_password;
        int EmployeeID;
        cout<<"Enter employeeID";
        cin>>EmployeeID;
        cout<<endl<<"Enter Employee Name";
        cin>>Name;
        cout<<endl<<"Enter Desgination";
        cin>>Designation;
        cout<<endl<<"Enter DOB";
        cin>>DOB;
        cout<<endl<<"Enter Employee Gender";
        cin>>Gender;
        cout<<endl<<"Enter emp_password";
        cin>>emp_password;
        db2.insertEmpData(EmployeeID, Name, Designation, DOB, Gender, emp_password);
   
    }

    void empUdate(){
        string  Name, Designation , DOB;
        int EmployeeID;
        cout<<endl<<"Enter the id of employee whose details need to be updated";
        cin>>EmployeeID;
        cout<<endl<<"Enter the Name";
        cin>>Name;
        cout<<endl<<"Enter Designation";
        cin>>Designation;
        cout<<"Enter DOB";
        cin>>DOB;
        db2.updateEmpData(EmployeeID, Name, Designation,DOB);
    }

    void empDel(){
        int empid;
        cout<<endl<<"Enter the employee id whose record need to be deleted";
        cin>>empid;
        db2.deleteEmpData(empid);
    }

    void empView(){
        int empid;
        cout<<endl<<"Enter employee id whose record you want to view";
        cin>>empid;
        db2.getEmpData(empid);
    }




int database::open_db() 
{
	int status = sqlite3_open("BANK.db", &db);
	if (status) {
		cout<<"Can't open database: \n"<<sqlite3_errmsg(db);
		return 0;
	}
	else {
		cout<<"Opened database successfully!\n";
	}
	return status;
}

// Function to Insert Employee Data
int database::insertEmpData(int empid,string name,string desig,string dob,string gender,string pass)
{
	string com = "','";
	string id = to_string(empid);
	string s = "INSERT INTO employee VALUES('" + id + com + name + com + desig + com + dob + com + gender + com + pass + "' );";
	rc = sqlite3_exec(db, s.c_str(),callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		cout << "Insert Error: "<<endl;
        sqlite3_free(messageError);
		return 0;
	}
	else {
		cout << "-> Record created successfully!" << endl;
		return 1;
	}
}

//fnction to update data of employees
int database::updateEmpData(int empid, std::string name, std::string desig, std::string dob)
{
	string id = to_string(empid);
	sql = "UPDATE employee SET Name='" + name + "',Designation='" + desig + "',DoB='" + dob + "' WHERE EmployeeID='" + id + "';";
	rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		cout << "Update Error: "<<endl;
		return 0;
	}
	else {
		cout << "-> Record updated successfully!" << endl;
		return 1;
	}
}

//function to display employee data
void database::getEmpData(int empid)
{
	string id = to_string(empid);
	sql = "SELECT * FROM employee WHERE EmployeeID="+id+";";
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
}
//function to delete employee data
int database::deleteEmpData(int empid)
{
	string id = to_string(empid);
	sql = "DELETE FROM employee WHERE EmployeeID='" + id + "';";
	rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	if (rc != SQLITE_OK) {
		cout << "Delete Error: " << endl;
		return 0;
	}
	else {
		cout << "-> Record deleted successfully!" << endl;
		return 1;
	}
}

void database::close_db()
{
	sqlite3_close(db);
}