//A program to simulate a simple banking system in which the initial balance and rate of interest are read from the keyword and these values
//are initialised using the constructor member function. The program consists of the following methods:
//->To initialise the balance amount and the rate of interest using the constructor member function
//->To make a deposit
//->To withdraw an amount from the balance
//->To find the compound interest based on the rate of interest
//->To know the balance amount
//->To display the menu options
#include<iostream>
using namespace std;
class account
{
private:
    float balance;
    float rate;
public:
    account();
    void deposit();
    void withdraw();
    void compound();
    void getbalance();
    void menu();
};
account :: account()
{

    cout<<"Enter the initial balance:"<<endl;
    cin>>balance;
    cout<<"Interest rate in decimal"<<endl;
    cin>>rate;
}
void account :: deposit()
{
    float amount;
    cout<<"enter the amount:"<<endl;
    cin>>amount;
    balance=balance+amount;
}
void account :: withdraw()
{
    float amount;
    cout<<"How much to withdraw?"<<endl;
    cin>>amount;
    if(amount<=balance)
    {
        balance=balance-amount;
        cout<<"Amount drawn="<<amount<<endl;
        cout<<"Current balance="<<balance<<endl;
    }
    else
        cout<<0;
}
void account :: compound()
{
    float interest;
    interest=balance*rate;
    balance=balance+interest;
    cout<<"Interest amount="<<interest<<endl;
    cout<<"Total amount="<<balance<<endl;
}
void account :: getbalance()
{
    cout<<"Current balance=";
    cout<<balance<<endl;
}
void account :: menu()
{
    cout<<"d->deposit"<<endl;
    cout<<"w->withdraw"<<endl;
    cout<<"c->compound interest"<<endl;
    cout<<"q->quit"<<endl;
    cout<<"m->menu"<<endl;
    cout<<"option, please?"<<endl;
}
int main()
{
    class account acct;
    char ch;
    acct.menu();
    while((ch=cin.get())!='q')
    {
        switch(ch)
        {
        case 'd':
            acct.deposit();
            break;
        case 'w':
            acct.withdraw();
            break;
        case 'c':
            acct.compound();
            break;
        case 'g':
            acct.getbalance();
            break;
        case 'm':
            acct.menu();
            break;
        }
    }
    return 0;
}
