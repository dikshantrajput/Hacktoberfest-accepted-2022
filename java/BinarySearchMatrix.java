package com.company.Property;

import java.util.Arrays;
//in this question sort a matrix row wise and column wise

public class BinarySearchMatrix {
    public static void main(String[] args) {
        int arr[][]={
                {10,20,30,40},
                {15,25,35,45},
                {28,29,31,49},
                {33,34,38,50}
        };
        int k[]=search(arr,35);
        System.out.println(Arrays.toString(k));

    }

    static int[] search(int[][] arr, int target){
        int r=0;
        int c=arr.length-1;
        while (r<arr.length && c>=0){
            if(arr[r][c]==target){
                return new int[]{r,c};
            }
            if (arr[r][c]<target){
                r++;
            }
            else {
                c--;
            }
        }
        return new int[]{-1,-1};
    }
}
