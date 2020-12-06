
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
                        getRecord();
                        break;
                case '2': printRecord();
                        break;
                case '3': updateDetails();
                        break;
                case '3': deposit_withdraw();
                break;
                case '5': break;
                default:customer_menu();
            }
