#include <bits/stdc++.h>

using namespace std;

int paintersPartitioning(std::vector<int> v, int n, int k)
{
	int low = *max_element(v.begin(), v.end());
	int high = 0;
	for (int i = 0; i < n; ++i)
	{
		high += v[i];
	}
	while(low < high)
	{
		int painters = 1;
		int mid = low + ((high - low)/2);
		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			temp += v[i];
			if(temp > mid)
			{
				painters++;
				temp = v[i];
			}
		}
		if(painters > k)
		{
			low = mid + 1;
		}
		else{
			high = mid;
		}
	}
	return low;
}

int main(int argc, char const *argv[])
{
	int n, k, x;
	std::vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	cout << paintersPartitioning(v, n, k) << endl;
}