#include<bits/stdc++.h>
using namespace std;
int helper(int* wt, int* val, int n, int w,int **dp){
    if(w==0||n==0){
        return dp[n][w]=0;
    }
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+helper(wt,val,n-1,w-wt[n-1],dp),helper(wt,val,n-1,w,dp));
    }
    else
        return dp[n][w]=helper(wt,val,n-1,w,dp);
}
int knapsack(int* weight, int* value, int n, int maxWeight) {
	int **dp;
    dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[maxWeight+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++)
            dp[i][j]=-1;
    }
    return helper(weight,value,n,maxWeight,dp);
    
}
int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}