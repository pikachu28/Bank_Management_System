#include <stdio.h>
#include<conio.h>
#include<process.h>
using namespace std;

void admin_menu()
{

}


void user(){


}



int main() {
char ch;

//clrscr();
cout<<"** Bank Management System";
cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\t01. LOGIN AS A CUSTOMER";
cout<<"\n\n\t02. LOGIN AS A ADMINISTRATOR";
cout<<"\n\n\t03. LOGIN AS A EMPLOYEE";
cout<<"\n\n\t04. EXIT";
cout<<"\n\n\tPlease Select Your Option (1-3) ";
cin>>ch;
switch(ch)
{
case '1': //clrscr();
    cout<<"\n\n Customer Menu";
	  user();
	  //getch();
break;
case '2':
cout<<" \n\n Admin Menu" ;
admin_menu();
break;
case '3': break;
default : break;
}

return 0;
}
