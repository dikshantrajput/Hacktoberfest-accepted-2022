#include<iostream> //Prime number
using namespace std;

int main(){
    int n;
    cin>>n;
int i;
    for( i=2;i<n;i++){
      if(n%i==0){
        cout<<"Non Prime"<<endl;
        break; 
      }
  
    }
    cout<<i;
    if(i==n){
        cout<<"Prime no."<<endl;
    }
    return 0;
}