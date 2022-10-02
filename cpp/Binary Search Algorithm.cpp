# include<iostream>
using namespace std;

int BinarySearch(int arr[], int start, int end, int key){    
    int mid;
    while(start <= end)
    {   
        mid = (start + end)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return -1;
}
int main(){
    int arr[]={10, 20, 30, 45, 65, 75, 90} ;
    int n = sizeof(arr) / sizeof(int) ; 
    int start = 0 , end = n-1 ;
    int key = 90 ;
    
    int index = BinarySearch(arr, start, end, key);
  
    if(index >= 0)
        cout<<"Key Found at index "<<index ; 
    else 
        cout<<"Key Not Found ";
    
    return 0;
}




