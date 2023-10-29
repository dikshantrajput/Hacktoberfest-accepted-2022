#include <bits/stdc++.h>

using namespace std;

 class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN,curr=0;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            if(sum<curr)
            sum=curr;

            if(curr<0)
            curr=0;
        }
        return sum;
    }
};
int main()
{
    Solution obj;
   int t;cin>>t;
   while(t--)
   {
       int n;//size of the input array
       cin>>n;
       int a;
    vector<int> v;//taking user input for the array
    for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = obj.maxSubArray(v);
    cout<<ans<<endl;
   }

    return 0;
}
