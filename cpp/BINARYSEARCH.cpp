#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start <= end)
    {
        if(arr[mid]==key)
         {   
            return mid;
         }
        if(key>arr[mid])
            {
                start=mid+1;
                
            }
        else
            {
                end=mid-1;
            }
         
         
         
         mid=start + (end-start)/2;
    }
 return -1;
}
int main()
{
    int size,key;
    cout<<"Enter the size of an array"<<endl;
    cin>>size;
   int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Enter the key to be searched "<<endl;
    cin>>key;
 int x=BinarySearch(arr,size,key);
   cout<<"The element is found at index "<<x<<endl;
return 0;
}