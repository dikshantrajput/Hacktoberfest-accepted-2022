//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int t[501][501];
    bool palindrome(string s1,int i ,int j)
    {
        
       if(i==j)
       return true;
       if(i>j)
       return true;
       
       while(i<j)
       {
           if(s1[i]!=s1[j])
           return false;
           
           i++;
           j--;
       }
       return true;
        
    }
    
    int solve(string s, int i , int j)
    {
        if(i>=j)
        return 0;
        
       
        
        if(palindrome(s,i,j))
        return t[i][j] = 0;
        
         if(t[i][j]!=-1)
        return t[i][j];
        
        int temp,ans=INT_MAX;
        int left,right;
        for(int k = i;k<=j-1;k++)
        {
            if(t[i][k]!=-1)
            {
                left = t[i][k];
            }
            else
            {
                left = solve(s,i,k);
            }
             if(t[k+1][j]!=-1)
            {
                right = t[k+1][j];
            }
            else
            {
                right = solve(s,k+1,j);
            }
            
            temp = 1+left+right;
            ans = min(temp,ans);
        }
        return t[i][j] = ans;
        
        
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        int n = str.length();
        return solve(str,0,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
