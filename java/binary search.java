package com.company;

public class Binarysearch {
    public static void main(String[] args) {
        int list[]={2,3,5,7,8,9};
int ans=search(list,9);
        System.out.println(ans);
    }static int search(int arr[],int value){
        int start=0,end= arr.length-1;
        int mid=(start+end)/2;
        while(start<=end) {
            if (value == arr[mid]) {
                return mid;
            }
            if (value > arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }

        return -1;
    }
}