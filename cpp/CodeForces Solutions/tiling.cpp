#include <iostream>
using namespace std;

int Noofways(int n){
    if(n==0 |n==1) 
    return n;
	
	return Noofways(n-1)+Noofways(n-2);
}

/*int tillingProblem(int n, int m){
    return tiles(n, m);*/


 int main(){
     cout<<Noofways(4)<<endl;
     cout<<Noofways(3)<<endl;
     return 0;
}
