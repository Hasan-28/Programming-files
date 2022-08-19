#include<iostream>
#include<fstream>

using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float dis,discount;
    string name,pname;

public:
    void menu();
    void adminstrator();
    void buyer();
    void add();
    void edit();
    void llist();
    void reciept();
    void rem();
    };
    void shopping ::menu()
    {
        m:
        int choice;
        string email;
        string password;

        cout<<"\t\t\t\t---------------------------------------------------------------\n";
        cout<<"\t\t\t\t                                                                                \n";
        cout<<"\t\t\t\t         SUPER MARKET MAIN MENU                 \n";
        cout<<"\t\t\t\t                                                                                 \n";
        cout<<"\t\t\t\t----------------------------------------------------------------\n";
        cout<<"\t\t\t\t    1)Administrator       \n";
        cout<<"\t\t\t\t                                      \n";
        cout<<"\t\t\t\t    2)Buyer                     \n";
        cout<<"\t\t\t\t                                       \n";
        cout<<"\t\t\t\t    3)Exit.                        \n";
        cout<<"\t\t\t\t                                       \n";
        cout<<"\t\t\t\t    Please Select           \n";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"-----Please Login :--------------\n";
            cout<<"-----Enter  your E-mail :--------\n";
            cin>>email;
            cout<<"-----Password :--------------------\n";
            cin>>password;

            if(email=="hasan@gmail.com" && password=="hasan123")
            {
             adminstrator();
            }
            else
            {
                cout<<"Invalid E-mail/Password";
                break;
            }
              //break;
     //   }
        case 2:
            {
                buyer();
                }
        case 3:
            {
                exit(0);
            }
        default:
            {
                cout<<"Please Select From the Given Options ";
            }

    }
    goto m;
    }
    void shopping ::adminstrator()
    {
         m:
        int choice;
        cout<<"\n\n\t\t\t    Administrator Menu          ";
         cout<<"\n\n\t\t\t                                              ";
        cout<<"\n\n\t\t\t   1) Add the Product..........!:";
        cout<<"\n\n\t\t\t                                              ";
        cout<<"\n\n\t\t\t    2)Modify The Product       ";
        cout<<"\n\n\t\t\t                                              ";
         cout<<"\n\n\t\t\t    3)Delete The Product      ";
          cout<<"\n\n\t\t\t                                              ";
          cout<<"\n\n\t\t\t    4) Back to Main Menu    ";

          cout<<"\n\n\t Please Enter Your Choice :";
          cin>>choice;

          switch(choice)
          {
          case  1:
            add();
            break;

          case 2:
            edit();
            break;

          case 3:
            rem();
            break;

          case 4:
            menu();
            break;

          default:
            cout<<"Invalid Choice ";
            }
            goto m;
        }

        void shopping ::buyer()
        {
             m:
            int choice;
            cout<<"\t\t\t   Buyer   \n";
            cout<<"\t\t\t---------------------   \n";
            cout<<"\t\t\t                              \n";
            cout<<"\t\t\t 1)  Buy Product   \n";
            cout<<"\t\t\t                               \n";
            cout<<"\t\t\t 2) Go Back           \n";
             cout<<"\n\n\t\t\t                         \n";
            cout<<"\t\t\t Enter Your Choice :";
            cin>>choice;

            switch(choice)
            {
            case 1:
                reciept();
                break;

            case 2:
                menu();
                break;

            default:
                cout<<"Invalid Choice ";
                }
                goto m;

            }

 void shopping ::add()
 {
     m:
     fstream data;
     int c;
     int token=0;
     float p;
     float d;
     string n,pname;


    cout<<"\n\n\t\t\t  Add New Product";
     cout<<"\n\n\t\t\t                                ";
     cout<<"\n\n\t\t\t  Product Code :";
     cin>>pcode;
     cout<<"\n\n\t Name of the Product :";
     cin>>pname;
     cout<<"\n\n\t Price of the Product :";
     cin>>price;
     cout<<"\n\n\t Discount on Product :";
     cin>>discount;

     data.open("database.txt",ios::in);
     if(!data)
{
         data.open("database.txt",ios::app|ios::out);
         data<<"   "<<pcode<<"   "<<pname<<"   "<<price<<"   "<<dis<<"\n";
         data.close();
     }
     else
     {
         data>>c>>n>>p>>d;
            while(!data.eof())
         {
             if(c==pcode)
         {
             token++;
         }
         data>>c>>n>>p>>d;
     }
     data.close();
     if(token==1)
        goto m;
        else{
              data.open("database.txt",ios::app|ios::out);
         data<<"   "<<pcode<<"   "<<pname<<"   "<<price<<"   "<<dis<<"\n";
         data.close();
        }
 }
 cout<<"\n\n\t Record Inserted :";
 }
void shopping ::edit()
     {
         fstream data,data1;
         int pkey;
         int token=0;
         int c;
         float p;
         float d;
         string n;

         cout<<"\n\t\t  Modify the Record ";
         cout<<"\n\t\t  Product Code        ";
         cin>>pkey;

         data.open("database.txt",ios::in);
         if(!data)
         {
             cout<<"\n\nFile Doesn't exist! ";
         }
         else{
            data1.open("database1,txt", ios::app|ios::out);

            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
         {
             if(pkey==pcode)
             {
                 cout<<"\n\t\t Product New Code :";
                 cin>>c;
                 cout<<"\n\t\t Name of the product :";
                 cin>>n;
                 cout<<"\n\t\t Price:";
                 cin>>p;
                 cout<<"\n\t\t  Discount:";
                 cin>>d;
                 data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
              cout<<"\n\t\t  Record Edited";
              token++;
             }
             else
             {
                 data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
             }
             data>>pcode>>pname>>price>>dis;
         }
         data.close();
         data1.close();

         remove("database.txt");
         rename("database1.txt","database.txt");

         if(token==0)
         {
             cout<<"\n\n\t  SORRY.......Record Not Found ";
         }
         }
     }
     void shopping ::rem()
     {
         fstream data,data1;
         int pkey;
         int token=0;
         cout<<"\n\n\t  Delete Product :";
         cout<<"\n\n\t  Product Code  :";
         cin>>pkey;
         data.open("database.txt",ios::in);
         if(!data)
         {
             cout<<"File Doesn't Exist";
         }
         else{
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==pkey)
                {
                    cout<<"\n\n\t Product Deleted Successfully";
                    token++;
                }
                else
                {
                    data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

if (token==0)
{
    cout<<"\n\n  Record not Found";
}

         }
     }

void shopping ::llist()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n---------------------------------------------------\n";
    cout<<"prono\t\tName\t\tPrice\n";
     cout<<"\n\n---------------------------------------------------\n";
     data>>pcode>>pname>>price>>dis;
     while(!data.eof())
     {
         cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
         data>>pcode>>pname>>price>>dis;
     }
     data.close();
}
void shopping ::reciept()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t  RECEIPT  ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n  Empty Database ";
        }
        else{
            data.close();
            llist();
            cout<<"\n-----------------------------------------------------------------------------------\n";
             cout<<"\n                                                                                                       \n";
            cout<<"\n                            Please Place  the Order                                   \n";
            cout<<"\n                                                                                                       \n";
             cout<<"\n-----------------------------------------------------------------------------------\n";
             do{
                cout<<"\n\n  Enter Product Code :";
                cin>>arrc[c];
                cout<<"Enter the Product Quantity :";
                cin>>arrq[c];
                for(int i=0;i<c;i++)
                {
                    if(arrc[c]==arrc[i])
                    {
                        cout<<"\n\n  Duplicate Product Code......Please Try Again!";
                        goto m;
                    }
                }
                c++;
                cout<<"\n\n\t  Do you want to buy another product or not? if yes Press 'y' else no";
                cin>>choice;
             }
             while(choice=='y');

                cout<<"\n\n\t\t---------------------------Receipt---------------------------\n";
             cout<<"\n  Product Number\t Product Quantity\t Price\t Amount with discount\n";

             for(int i=0;i<c;i++)
             {
                 data.open("database.txt",ios::in);
                 data>>pcode>>pname>>price>>dis;
                 while(!data.eof())
                 {
                     if(pcode==arrc[i])
                     {
                         amount=price*arrq[i];
                         dis=amount-(amount*dis/100);
                         total=total+dis;
                         cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                     }
                     data>>pcode>>pname>>price>>dis;
                     }
                 }
                 data.close();
        }
        cout<<"\n\n-----------------------------------------------------------------------------------------------------";
        cout<<"\n  Total Amount  :"<<total;
}
int main()
{
       shopping o;
    o.menu();
}


