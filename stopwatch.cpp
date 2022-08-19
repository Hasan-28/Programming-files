#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int main()
{
    system("cls");
    int h=0,m=0,s=0;
    cout<<"\n\n\n\t Press any key to Continue.\n";
    cout<<"\n\n\n\t Stop Watch \n";
    cout<<"\n\n\n\t HH:MM:SS";

    cout<<"\n\n\n\t "<<h<<" : "<<m<<" : "<<s;
    getch();
    while(!_kbhit())
    {
        s++;
        Sleep(1000);
        if(s>59)
        {
            m++;
            s=0;
        }
        if(m>59)
        {
            h++;
            m=0;
        }
        system("cls");
        cout<<"\n\n\n\t  Stop Watch";
        cout<<"\n\n\n\t HH:MM:SS";
        cout<<"\n\n\n\t"<<h<<":"<<m<<":"<<s;
        cout<<"\n\n\n\t Press Any key to Stop :";
        }
        getch();
        cout<<"\n\n\n\t Paused :";
        cout<<"\n\n\n\t"<<h<<" : "<<m<<" : "<<s;
        getch();
        return 0;
}
