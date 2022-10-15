package RECURSION;

public class BinarySearch_R {
    static boolean binarySearch(int[] arr , int s, int e, int key){
        if(s>e){
            return false;
        }
        int mid = s+(e-s)/2;
        if(arr[mid] == key){
            return true;
        }
        if(arr[mid]<key){
            return binarySearch(arr,mid+1,e,key);
        }
        else {
            return binarySearch(arr,s,mid-1,key);
        }
    }
    public static void main(String[] args) {
        int[] arr = {4,5,7,8,9,10};
        int size = 6;
        int key = 1;

        System.out.println("present or not " + binarySearch(arr,0,5,key));
    }
}
