#include <iostream>
#include <math.h>
using namespace std;

int base10tobase2(int n){
    int count=0, ans=0 ,rem ;
    while(n!=0){
        rem=n%2;
        ans+=pow(10,count)*rem;
        count++;
        n/=2;

    }
    return ans;
}



int main(){
    int n;
    cout<<"Enter a decimal number : ";
    cin>>n;
    cout<<"Binary number of "<<n<<" is "<<base10tobase2(n)<<endl;
    

    return 0;
}
