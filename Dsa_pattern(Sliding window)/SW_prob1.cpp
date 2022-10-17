//Problem Statement
//Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’
//Test case--01
/*
Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
*/
//My code 

#include <iostream>
#include <vector>
using namespace std;

int findMaxSumSubArray(int k, vector<int>& arr) {
    int maxSum = 0;
    int sum=0;
    int start_win=0,end_win=0;
    while(end_win<arr.size()){
      sum+=arr[end_win];
      if(end_win>=k-1){
        //window size is reached now we can slide the window and perform our calculations
        maxSum=max(maxSum,sum);
        sum-=arr[start_win];
        start_win++;
      }
      end_win++;
    }
    return maxSum;
  }
int main(){
vector<int>arr={2,1,5,1,3,2};
cout<<findMaxSumSubArray(3,arr);
}
//This approach will save us from re-omputing the sum of the overlapping part of the sliding window.
/*
Time Complexity --> O(N)
Space Complexity --> O(1)
*/