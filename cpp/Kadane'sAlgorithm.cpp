/*Kadane's Algorithm is an iterative dynamic programming algorithm, which is used to find the maximum sum of a subarray in the given array.
# SubArray
Sub array is a part of the array which contains elements contiguously.
A subarray must contain atleast one element, atmost it can contain all the elements of the array.
# Maximum Sum of The SubArray 
-Finding maximum sum of the elements in a subarray. 
-Using Brute Force approach the Time Complexity is O(n^3). 
-Kadane's Algorithm is an efficient approach where the Time Complexity is O(n).
# Kadane's Algorithm
Kadane's algorithm is used to find the maximum sum of a subarray in the given array .
Algortithm : 
-Defining a function MaxSum which takes array and its size as parameters.
-SubSum is the variable which keeps storing the sum of the subarray as we iterate through the elements of the array. it is initialised to zero.
-MaxSum is the variable which stores the maximum value of sum. 
-The value of SubSum is incremented further only if the previous value is positive, if it is negative we re-initialise the value of SubSum to zero.
-If the value of SubSum is greater than MaxSum then assign its value to MaxSum.
-Print the value of MaxSum.
*/




#include<iostream>
using namespace std;
void MaxSum(int arr[],int n){
    int SubSum = 0;
    int Max = arr[0];
    for(int i=0;i<n;i++){
        SubSum += arr[i];
        /*if(SubSum > Max){
            Max = SubSum;
        }*/
        //replace with max function before checking if its less than 0 as their might be arrays with all negative elements in such cases Max returns 
        // least negative set of digits 
        //if we keep this statement after subsum<0 it will update to 0 and give 0 which is wrong output 
        Max=max(SubSum,Max);
        if(SubSum < 0){
            SubSum = 0;
        }
    }
    cout<<"Max sum is: "<<Max;
}
int main(){
    int size, arr[100];
    cout<<"Number of array elements: ";
    cin>>size;
    cout<<"give array: ";
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    MaxSum(arr,size);
}
