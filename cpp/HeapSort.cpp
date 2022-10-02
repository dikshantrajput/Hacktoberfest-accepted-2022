#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        //Recursively heapifying the sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}
int main()
{
    int arr[] = {1, 14, 3, 7, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array  \n";
    display(arr, n);
    
    heapSort(arr, n);
 
    cout << "Sorted array  \n";
    display(arr, n);
}
