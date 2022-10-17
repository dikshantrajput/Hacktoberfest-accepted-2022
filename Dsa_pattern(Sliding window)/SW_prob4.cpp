// Problem Statement
// Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter,
//  find the length of the longest substring having the same letters after replacement.
/*
Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".
*/
// My code

#include <bits/stdc++.h>
using namespace std;

int findMaxSubArray(int k, string S)
{
    int s = 0, e = 0, mc = 0, maxLength = 0;
    unordered_map<char, int> letterFrequencyMap;
    while (e < S.length())
    {
        char rc = S[e];
        letterFrequencyMap[rc]++;
        mc = max(mc, letterFrequencyMap[rc]);
        if (e - s + 1 - mc > k)
        {
            // shrink the window
            char lc = S[s];
            letterFrequencyMap[lc]--;
            s++;
        }
        maxLength = max(maxLength, e - s + 1);
        e++;
    }
    return maxLength;
}
int main()
{
    string S;
    int K;
    cin >> S >> K;
    cout << findMaxSubArray(K, S);
}
/*
this is just a sliding window problem that we do
we know that we want longest substring with repeating characters here
that means in that substring (which will be the longest) there should be all the same characters
except the k characters or less than k characters which we can replace.
overall we have a letter which is repeating 'mc' times, this means we can have a window which has one
letter repeating 'mc' times and the remaining letters we should replace (<=k).
if the remaining letters are more than 'k', it is the time to shrink the window as we are not allowed to replace more than 'k' letters
We only expand the window when the frequency of the newly added character exceeds the 
previously calculated maximum frequency.
Time Complexity --> O(N)
Space Complexity --> O(1)
*/