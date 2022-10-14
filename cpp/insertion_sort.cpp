/*
Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.

*/
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;

        while(j>=0 && temp<arr[j])
        {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

//printting the array
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    insertion_sort(arr,n);

    cout<<"The sorted Array is: "<<endl;
    printArray(arr,n);
    return 0;
}