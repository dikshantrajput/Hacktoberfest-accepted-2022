/*
This perticular file contains 
the Algorithm for Binary Search

This will return the index of the key element

That is in my openion Divide and find

*Dependancies
The array must be sorted

*approach
1. First find the mid of the array
2. check the mid element
2(a). if it is equal the !!you got the element
2(b). if the value is grater then check for the
     mid point of right side array and repeat the process
2(c). else check in the left side array and reoeat the process
3. Not found the value just return NULL or -1
 */

//Including
#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int Search(vector<int> arr, int key);
//This is the function we are going to use to find the key in array


int main(){
    vector<int> array = {256, 123, 900, 375, 894, 100, 0};
    //this is the vector we are going to search in "array"

    cout << Search(array, 100);
}

int Search(vector<int> arr, int key)
{
    //Lets first sort the given array
    sort(arr.begin(), arr.end());

    int start = 0, end = arr.size() - 1;
    //The required values

    int mid = (start + end) / 2;
    //the middle element index of the array

    while(start <= end)//
    {
        if(arr[mid] == key)
        {
            return mid;//Finds the value
        }
        else if(arr[mid] < key)
        {//if the value is larger
            start = mid + 1;
        }
        else
        {//if the key is smaller
            end = mid - 1; 
        }

        mid = (start + end) / 2;//Update the value of mid
    }
    return -1;//if not find the key in the array
    
}





/*
Thanks Section
https://www.geeksforgeeks.org/sorting-a-vector-in-c/
https://www.youtube.com/c/CodeHelpbyBabbar
*/