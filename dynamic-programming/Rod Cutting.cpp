
#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &price, int n) {
        int ans=0;
        if (n==0) return 0;
        if (n==1) return price[0];
        int dp[n+1];
        dp[0] =0;
        dp[1] = price[0];
        for(int i=2;i<=n ;i++)
        {
            dp[i]=0;
            for(int  j=0;j<i ;j++)
            {
                dp[i]= max(dp[i] ,price[j]+ dp[i-j-1]);
            }
        }
        return dp[n];
    }
int main() 
{
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = 8;
  cout<<"Maximum obtainable amount by cutting rod is "<<cutRod(price , n)<<endl;
  return 0;
}
