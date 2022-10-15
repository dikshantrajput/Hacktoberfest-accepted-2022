#include<bits/stdc++.h>
using namespace std;

vector <long long> eratos(int r){
    vector <bool> prime(r+1,true);
    vector <long long> ans;

    prime[0]=prime[1]=false;

    for(int i = 2 ; i<r;i++){
        if(prime[i]){
            ans.push_back(i);
            for(int j = 2*i ; j<r; j=j+i){
                prime[j] = 0;
            }
        }
    }

    return ans;
}

void segmented(long long int low,long long int high){

    int target = floor(sqrt(high));
    vector <long long> ans = eratos(target);
    vector <bool> isPrime(high-low+1,true);

    for(int i = 0; i<ans.size();i++){
        long long sm = (low/ans[i])*ans[i];

        if(sm<low){
            sm = sm+ans[i];
        }

        for(long long j =sm ; j<high ; j +=ans[i]){
            isPrime[j-low] = 0;
        }
    }

    for(long long i = low; i<high ; i++){
        if(isPrime[i-low] == true)
            cout<<i<<" ";
    }
    cout<<endl;

}

int main(){
    segmented(12,20);
    return 0;
}