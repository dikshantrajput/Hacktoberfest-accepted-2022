/*
Bubble Sort
This is the Algorithm For Sorting

*Approach
Here we check and swap the values in the array
*/

//Including
#include<iostream>

using namespace std;

void Transverse(int arr[], int size);
//For transversing the array

void Sort(int arr[], int size);
//The Function for Sorting using Bubble Sort

int main()
{
    int arr[100] = {10, 200, 20, 2579, 38, 17, 17, 12, 13, 12};
    //The array we are going to sort
    
    int size = 10;
    //The size of the array
    
    //Before Sorting
    Transverse(arr, size);
    
    
    //Now lets use the sorting Function
    Sort(arr, size);

    cout << endl;

    //After Sorting
    Transverse(arr, size);

    return 0;

}


void Sort(int arr[], int size)
{
    for(int i = 0; i < size; i ++)
    //the loop will run size times
    {
        for(int k = 0; k < size - i - 1; k ++)
        //this loop will run size - 1 times with "i" as its initial value
        {
            if(arr[k] > arr[k + 1])
            //Then swap the values 
            {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

void Transverse(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

/*
*Time Complaxity
O(size^2)
*/

/*
Thanks to
*/