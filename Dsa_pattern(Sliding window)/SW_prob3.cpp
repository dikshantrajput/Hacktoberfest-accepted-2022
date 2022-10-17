//Problem Statement
//Given a string, find the length of the longest substring in it with no more than K distinct characters.
/*
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
*/
//My code 

#include <bits/stdc++.h>
using namespace std;

int findMaxSubArray(int k, string S) {
   int start=0,end=0;
   unordered_map<char,int>freq_mp;
    int sum=0,mx=INT_MIN;
    while(end<S.length()){
        char c=S[end];
        freq_mp[c]++;
        while(freq_mp.size()>k){            
            char c=S[start];
            freq_mp[c]--;
            if(freq_mp[c]==0) freq_mp.erase(c);
            start++;
        }
        mx=max(mx,end-start+1);
        end++;


      }
    return mx;
  }
int main(){
string S;
int K;
cin>>S>>K;
cout<<findMaxSubArray(K,S);
}
//In this problem the size of sliding window is not fixed
/*
First, add the character of current index to the hashmap, if the character inside the window exceed k shrink the size of 
window until the number of characters in window becomes less than k (we will do this with the help of hashmap), if not then
calculate the size of window and update the maximum window size . While shrinking, we’ll decrement the character’s frequency going out of
the window and remove it from the HashMap if its frequency becomes zero.
Time Complexity --> O(N)
Space Complexity --> O(K)
*/