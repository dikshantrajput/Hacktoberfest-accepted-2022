#include <bits/stdc++.h>
using namespace std;
int precedenceChecker(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1; // not an operator and return on opening bracket
    }
}
string infixToPostfixConvertion(string s)
{
    stack<char> st;
    int length = s.length();
    string result;

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            result += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedenceChecker(st.top()) > precedenceChecker(s[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPostfixConvertion(s) << endl;
}
// (a-b/c)*(a/k-l)
