// bubble sort
// sorting algorithms can be used for collection of numbers, strings characters or a structure of any of theese types
// bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements and then swapping their positions if they exist in the wrong order.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}
int main()
{
    // take array as input
    int n; // n is the size of the array
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the array : ", i + 1);
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("Sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
