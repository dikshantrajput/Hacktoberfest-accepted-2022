#include <bits/stdc++.h> 
using namespace std; 

class Solution
{
public:

    const long long int mod = 1000000007;
    long long int findways(int n, vector<long long int>& no_of_ways)
    {
        if(n<0)
            return 0;
        
        if(no_of_ways[n]!=-1)
            return no_of_ways[n];
        
        return no_of_ways[n] = (findways(n-1, no_of_ways) + ((n-1)*findways(n-2, no_of_ways))%mod)%mod;
            
    }

    int countFriendsPairings(int n) 
    { 
        vector<long long int> no_of_ways(n+1, -1);
        no_of_ways[0] = 1;
        
        return (int)findways(n, no_of_ways);
    }
};    
 
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 