// Problem Statement
//Given a string and a pattern, find out if the string contains any permutation of the pattern. 
//Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:
//abc,acb,bac,bca,cab,cba
/*
Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
*/
// My code

#include <bits/stdc++.h>
using namespace std;

bool findMaxSubArray(string S,string p)
{
    int s = 0, e = 0;
    unordered_map<char, int> pattern;
     for(char i:p){
            pattern[i]++;
        }
        int count=pattern.size();
    while(e<S.length()){
            if(pattern.find(S[e])!=pattern.end()){
                pattern[S[e]]--;
                if(pattern[S[e]]==0)
                    count--;
            }
            if(e-s+1<p.size())
                e++;
            else if(e-s+1==p.size()){
                //window size hit
                if(count==0) return true;
                if(pattern.find(S[s])!=pattern.end()){
                    pattern[S[s]]++;
                    if(pattern[S[s]]==1) count++;
                }
                s++;
                e++;
            }
        }
    return false;
}
int main()
{
    string S,p;
    cin >> S >> p;
    cout << findMaxSubArray(S, p);
}
/*
Here with the problem statement we can oberseve that it is a fixed sliding window problem, the size of the window here will be the size of the
pattern given.
so the first step is to create a hashmap to store the frequency of the characters of pattern, in this way we can easily iterate over the string finding the 
possible permutation of the string
now keep your start and end pointers at the start of the string check if the newly added character is belongs to your pattern if yes, decrease
the frequency of that character from your map and if the frequency of that character becomes zero decrement the count variable because you have found
one character of the possible permutation(pattern)
while iterating over the while loop check that if you hit the size of the window....there can be two possibilities
one is that you have found your possible permutation in that case your count variable will become 0 
if it is not zero then that window is not the permutation now start shifting your window towards right and maintain the count variable
Time Complexity --> O(N)
Space Complexity --> O(p)
*/