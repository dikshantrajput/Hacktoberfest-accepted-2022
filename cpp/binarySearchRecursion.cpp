#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr,int s,int e,int key){
    
    int mid = (s+e)/2;
    //base case
    if(s>e){
        return false;
    }

    if(arr[mid] == key){
        return true;
    }
    
    if(arr[mid] < key){
        return binarySearch(arr,mid+1,e,key);
    }
    
    else{
        return binarySearch(arr,s , mid-1,key);
    }

}
 
int main(){
 
    int arr[5] = {1,3,5,7,9};
    int key = 7;
    int s = 0;
    int e = 4;

    bool ans = binarySearch(arr,s,e,key);

    if(ans){
        cout<<"element is present";
    }
    else{
        cout<<"element is not present";
    }
 
    return 0;
}