#include <bits/stdc++.h>
using namespace std;
 
int maxSubArray(vector<int>& nums) 
{
        int res = INT_MIN;
        int maxend = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxend = max(maxend+nums[i],nums[i]);
            res = max(res,maxend);
        }
        return res;
}

int main()
{
    vector<int> vect{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int max_sum = maxSubArray(vect);
    cout << "Maximum contiguous sum is->  " << max_sum;
    return 0;
}
