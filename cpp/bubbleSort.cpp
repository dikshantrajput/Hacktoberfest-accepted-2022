#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&arr){
  for(int i=0;i<arr.size(); i++){
    bool swaped=false;
    for(int j=0; j<arr.size()-1-i; j++){
      if(arr[j]>arr[j+1]){
        swaped=true;

        int t =arr[j+1];

        arr[j+1]=arr[j];
        arr[j]= t;
      }

    }
    if(swaped==false){
      break;
    }
}
  for(int ele:arr){
     cout<<ele<<" ";


     }
     cout<<"\n";

 }

int main(){
  vector<int>arr={1,4,6,8,5,9};
  bubbleSort(arr);
