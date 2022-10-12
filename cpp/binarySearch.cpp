#include<iostream>
using namespace std;
//Iterative Method;
int binarySearch(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(key==arr[mid]) return mid;
        else if(key<arr[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
//Recursive
int R_binarySearch(int arr[],int n,int l,int r,int key){
    if(l>r) return -1;
    int mid=(l+r)/2;
    if(key==arr[mid]) return mid;
    else if(key<arr[mid]) return R_binarySearch(arr,n,l,mid-1,key);
    else return R_binarySearch(arr,n,mid+1,r,key);
    return -1;
}
int main(){
    int size;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++) cin>>arr[i];
    int key;
    cout<<"Enter an element to be searched : ";
    cin>>key;
    int index=R_binarySearch(arr,size,0,size-1,key);
    if(index!=-1){
        cout<<"Element found at "<<index+1<<" position."<<endl;
    }
    else cout<<"Not found."<<endl;
    return 0;
}