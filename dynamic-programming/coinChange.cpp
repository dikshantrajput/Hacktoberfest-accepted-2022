#include <bits/stdc++.h>

using namespace std;

long countWaysToMakeChangeUtil(vector<int>& arr,int ind, int T, vector<vector<long
>>& dp){

    if(ind == 0){
        return (T%arr[0]==0);
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    long notTaken = countWaysToMakeChangeUtil(arr,ind-1,T,dp);
    
    long taken = 0;
    if(arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken + taken;
}


long countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<vector<long>> dp(n,vector<long>(T+1,-1));
    return countWaysToMakeChangeUtil(arr,n-1, T, dp);
}

int main() {

  vector<int> arr ={1,2,3};
  int target=4;
  
  int n =arr.size();
                                 
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
}