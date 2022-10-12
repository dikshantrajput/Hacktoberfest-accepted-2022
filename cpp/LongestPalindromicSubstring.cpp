#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s.size();
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;)
        {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1])
            {
                ++right;
                --left;
            }
            if (max_len < right - left + 1)
            {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return max_len;
    }
};
int main()
{

    Solution ob;
    string s;
    cout << "Enter a String :" << endl;
    cin >> s;
    cout << ob.longestPalindrome(s) << endl;
    return 0;
}