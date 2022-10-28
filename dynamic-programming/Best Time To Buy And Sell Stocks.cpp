
#include <bits/stdc++.h>

using namespace std;

int maximum_profit(const std::vector<int> &prices)
{
    int min_price = std::numeric_limits<int>::max();
    int max_profit = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        if (prices[i] < min_price)
        {
            min_price = prices[i];
        }
        else if (prices[i] - min_price > max_profit)
        {
            max_profit = prices[i] - min_price;
        }
    }
    return max_profit;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << maximum_profit(nums) << endl;
    }
    return 0;
}