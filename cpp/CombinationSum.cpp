#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&ans, vector<int>&v, vector<int>&candidates, int target, int n)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(n<=0 || target<0)
        {
            return ;
        }
        
        v.push_back(candidates[n-1]);
        solve(ans, v, candidates, target-candidates[n-1], n);
        v.pop_back();
        solve(ans, v, candidates, target, n-1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        int n=candidates.size();

        solve(ans, v, candidates, target, n);

        return ans;
    }

int main()
{
  int n, a, target;
  cout<<"No of elements : ";
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>a;
    candidates.push_back(a);
  }
  cout<<"Enter the target : ";
  cin>>target;
  
  vector<vector<int>>ans=combinationSum(candidates, target);
  cout<<"Required sets are : ";
  for(auto it:ans)
  {
    for(auto x: it)
        cout<<x<<" ";
    cout<<endl;
  }
  return 0;
  }
