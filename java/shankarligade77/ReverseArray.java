import java.util.*;
public class ReverseArray {
    public static void main(String[] args)
    {
        int[] arr={1,2,5,3,7,2,1};
        int l=0;
        int h=arr.length-1;
        while(h>l){
            int temp=arr[h];
            arr[h]=arr[l];
            arr[l]=temp;
            h--;
            l++;
        }
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
