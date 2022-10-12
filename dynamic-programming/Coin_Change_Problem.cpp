const int N=1e3+5;

long long dp[N][N];

class Solution {

  public:

    long long int count(int coins[], int N, int sum) {

        

        if(sum==0)return 1*1LL;

        if(sum<0)return 0;

        if(N==0)return 0;

        if(dp[sum][N]!=0)return dp[sum][N];

        return dp[sum][N]=count(coins,N,sum-coins[N-1])+count(coins,N-1,sum);

    }

};
