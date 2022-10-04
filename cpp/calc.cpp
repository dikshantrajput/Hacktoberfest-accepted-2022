#include <iostream>
using namespace std;
const int a= 10;
int total(int b)
{
    int c= a*b;
    return c;
}
int discount(int d)
{
    int e= d/1.08;
    return e;
}
int main()
{
    int quantity, amount;
    float change;
    char disc;
cout<<"Enter quantity"<<endl;
cin>>quantity;
system("cls");
cout<<"Quantity= "<<quantity<<endl;
cout<<"Order Total= "<<total(quantity)<<endl;
cout<<"Discount Applied(Y/N)";
cin>>disc;
amount= total(quantity);
if(disc=='Y' || disc=='y')
{
    cout<<"Total after discount= "<<discount(amount)<<endl;
    cout<<"Thanks For Your Order";
}
if (disc=='N' || disc=='n')
{
    cout<<"Thanks For Your Order"<<endl;
}
if (disc=='+')
{
    cout<<"Enter Percentage";
    cin>>change;
    cout<<"Total after discount of "<<change<<" = "<<amount/change;
}

return 0;
}   
