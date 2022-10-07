#include <iostream>
#include <stack>

using namespace std;

void reverseStr(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word = " ";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }

        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{

    string s; // s is string object-> string is a class and char is a datatype.

    getline(cin, s); // with string use getline(cin/cout, obj_name)--> default delimiter is \n. delimter is used to stop the getline function.

    // with char (char_name) or char char_name[] use cin.getline(char_name, max_size) function.

    // getline used to accept a group of words including space.

    reverseStr(s);
}
