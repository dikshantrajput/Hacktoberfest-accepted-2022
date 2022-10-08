#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];
/* Palindrome Partitioning 

I/O:
GEKES -> G|EKE|S  (minimum 2 partition and each partiotion is palindrome)

O/P:
2
**/
bool isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return true;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int solve(string s, int i, int j)
{
    if (t[i][j] != -1)
        return t[i][j];

    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    int m = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // for further optimisation check whether "sub-functions" are already called or not.
        int l, r;
        if (t[i][k] != -1)
            l = t[i][k];
        else
        {
            l = solve(s, i, k);
            t[i][k] = l;
        }
        if (t[k + 1][j] != -1)
            r = t[k + 1][j];
        else
        {
            r = solve(s, k + 1, j);
            t[k + 1][j] = r;
        }
        // int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
        int temp = l + r + 1;
        m = min(temp, m);
    }

    return t[i][j] = m;
}

int main()
{
    memset(t, -1, sizeof(t));
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1);

    return 0;
}
