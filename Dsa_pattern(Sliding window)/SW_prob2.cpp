//Problem Statement
//Given an array of positive integers and a number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.
/*
Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [5, 2]
*/
//My code 

#include <bits/stdc++.h>
using namespace std;

int findMinSubArray(int S, vector<int>& arr) {
   int start=0,end=0;
    int sum=0,mn=INT_MAX;
    //add elements to window until your sum bec greater than or equal to target
    while(end<arr.size()){
      sum+=arr[end];
     while(sum>=S){
      mn=min(end-start+1,mn);
       sum-=arr[start];
          start++;
        }
      
      end++;
    }
    return mn;
  }
int main(){
int n,S;
cin>>n>>S;
vector<int>arr;
for(int i=0;i<n;i++){
    int x;cin>>x;
    arr.push_back(x);
}
cout<<findMinSubArray(S,arr);
}
//In this problem the size of sliding window is not fixed
/*
First, we will add-up elements from the beginning of the array until their sum becomes greater than or equal to S.
These elements will be considered as a part of our sliding window. 
Each time we get the sum greater than or equal to S we will update the size of our window as we have to return the minimum sized window.
After this, we will keep adding one element in our window.
After getting the sum greater than or equal to S, we will shrink the window from the beginning until the window’s sum is smaller than ‘S’.
Time Complexity --> O(N)
Space Complexity --> O(1)
*/