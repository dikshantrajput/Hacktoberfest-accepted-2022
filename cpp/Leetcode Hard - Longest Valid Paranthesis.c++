// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxm = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (st.empty())
                st.push(i);
            else
            {
                maxm = max(maxm, i - st.top());
            }
        }
    }

    return maxm;
}

int main()
{
    string s;
    cin >> s;
    int len = longestValidParentheses(s);
    cout << len << endl;
    return 0;
}