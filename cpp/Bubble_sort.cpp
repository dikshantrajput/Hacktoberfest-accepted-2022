#include <bits/stdc++.h>
using namespace std;

void Bubble_Sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	
    cout << endl;
}

int main()
{
	int N;
    
    cout<<"Enter the size of Array: ";
    cin>>N;

    int arr[N];
    
    cout<<"Enter the elements in Array"<<endl;
    for(i = 0; i < size; i++)
        cin>>arr[i];

	Bubble_Sort(arr, N);
	cout << "Sorted array: \n";
    printArray(arr, N);
	
    return 0;
}