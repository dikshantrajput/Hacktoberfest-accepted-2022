#include <iostream>

using namespace std;

int lcs(string X , string Y , int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0; i < n+1 ; i++)
    {
        for(int j=0; j < m+1; j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0; i < n+1; i++)
    {
        for(int j=0; j < m+1; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            
            }
            else if(X[i-1]==Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j] ,dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1,s2;
   
    //int s=s1.size();

    cin>>s1>>s2;
    int p=s2.size();
    int s=s1.size();
    //lcs(s1,s2,s,p);
    cout<<lcs(s1,s2,s,p);
