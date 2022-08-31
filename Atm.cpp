#include<iostream>
using namespace std;
void showMenu()
{
    cout<<"**************************MENU*************************"<<endl;
    cout<<   "  1. CHECK BALANCE "<<endl;
    cout<<   "                                          "<<endl;
    cout<<   "  2.DEPOSIT                  "<<endl;
    cout<<   "                                          "<<endl;
    cout<<   "  3.WITHDRAW             "<<endl;
    cout<<   "                                          "<<endl;
    cout<<   "  4.EXIT                          "<<endl;
    cout<<"**********************************************************"<<endl;
}
int main()
{
    int option;
    double balance = 500;
    do
    {
        showMenu();
        cout<<"Option :";
        cin>>option;
        system("cls");
        switch(option)
        {
        case 1:
            cout<<  "Balance is : " <<balance<<" /-"<<endl;
            break;
        case 2:
            cout<<  "Deposit Amount :";
            double depositAmount;
            cin>>depositAmount;
            balance += depositAmount;
            break;
        case 3:
            cout<< " Withdraw Amount :";
            double WithdrawAmount;
            cin>>WithdrawAmount;
            if(WithdrawAmount <= balance)
                balance  -= WithdrawAmount;
            else
                cout<< " Not Enough Money "<<endl;
            break;
        }
    }
    while(option!=4);
    system("pause>0");
}
