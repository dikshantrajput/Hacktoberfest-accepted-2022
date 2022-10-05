// https://leetcode.com/problems/longest-palindromic-substring/
// Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

// A string is called a palindrome string if the reverse of that string is the same as the original string.
// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// Approach 1: Brute Force
// Intuition and Algorithm
// If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. 
// Complexity Analysis with brute force
// Time complexity : O(n^3).
// Space complexity : O(1).

// Approach 2: Dynamic Programming
// Intuition and Algorithm
// How can we reuse a previously computed palindrome to compute a larger palindrome?
// If “aba” is a palindrome, is “xabax” a palindrome? Similarly is “xabay” a palindrome?
// Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.

// Complexity Analysis with dynamic programming
// Time complexity : O(n^2). This gives us a runtime complexity of O(n^2).
// Space complexity : O(n^2). It uses O(n^2) space to store the table.

// Solution using dynamic programming

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));//dp[i][j] denotes whether the substring s[i...j] is a palindrome or not
        int start=0,end=0;//stores the start and end index of the longest palindrome
        for(int i=0;i<n;i++){
            dp[i][i]=true;//every single character is a palindrome
            for(int j=0;j<i;j++){
                if(s[i]==s[j] && (i-j<=2 || dp[j+1][i-1])){//if the characters at the start and end are equal and the substring between them is a palindrome
                    dp[j][i]=true;//then the substring s[j...i] is a palindrome
                    if(i-j>end-start){//if the length of the current palindrome is greater than the length of the longest palindrome
                        start=j,end=i;//update the start and end index of the longest palindrome
                    }
                }
            }
        }
        return s.substr(start,end-start+1);//return the longest palindrome
    }
};