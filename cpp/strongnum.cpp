#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    
    for(int i = 1; i <= n; i++)
            fact = fact * i;
    
    return fact;
}

int Strongnum(int num){
    
    int digit, sum = 0;
    int temp = num;
    
    while(temp!=0){
        digit = temp % 10;
        
        sum = sum + factorial(digit);
        temp /= 10;
    }
    
    
    return sum == num;
    
}
int main ()
{
    int num = 120;
    
    if(Strongnum(num))
        cout << num << " is Strong Number";
    else
        cout << num << " is Not Strong Number";

}
