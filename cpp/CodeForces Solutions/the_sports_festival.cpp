#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long int
#define INF 1e9

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    for (ll &x : a)
        cin >> x;
    sort(a, a + n);
    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + a[j + i] - a[j];
    cout << dp[n - 1][0] << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
}