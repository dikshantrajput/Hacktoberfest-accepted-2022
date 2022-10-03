#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int max = 0,ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[max]) max = i;
        }
        return max;
    }
int main(){
  vector<int> v;
  int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        v.push_back(x); //O(1)
    }
  cout<<findPeakElement(v)<<endl;
  return 0;
}
