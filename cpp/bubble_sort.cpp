#include<iostream>
using namespace std;

int* bubbleSort(int arr[], int n)
    {
        for(int i=0; i<n-1; i++) {
            int swapped = false;
            for(int j=0; j<n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapped=true;
                }
            }
            if(swapped == false)
                break;
        }
        return arr;
    }

int main()
{
  int n;
  cin>>n;
  int arr[n];
  
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  
  bubbleSort(arr,n);
  
  for(int i=0; i<n; i++) {
      cout<<arr[i]<<" ";
  }
}
