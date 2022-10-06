#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

//AKASH DINKAR PATIL 
//Q--> print all the subsets from given list. list may contains duplicates ,subset should not contains 
//dupliocates.
//eg->[1,2,2,2,3,3]
//o/p--> [[],[1],[2],[2],[1,2],[1,3],[1,2],[1,3,3],[2,3,3],[2,2,3,3],.....]

void subsetSumII(int index,vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans)
{
	ans.push_back(ds);
	

	for(int i=index;i<arr.size();++i)
	{
		if(i!=index && arr[i]==arr[i-1]) continue;

		//pick
		ds.push_back(arr[i]);
		subsetSumII(i+1,ds,arr,ans);
		ds.pop_back();

		


	}
}

int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	int n;
	cin>>n;
	vector<int>arr(n);
	vector<int>ds;
	vector<vector<int>>ans;
	for(int i=0;i<n;++i) cin>>arr[i];

	
	subsetSumII(0,ds,arr,ans);


	for(auto i :ans)
	{
		
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}

	
	/* code */
	return 0;
}

