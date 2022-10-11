import java.util.*;
public class ReverseArray {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length of array");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter element:");
            arr[i] = sc.nextInt();
        }
        revarray(arr, n);
        sc.close();
    }

    static void revarray(int arr[], int n) {
        int rev[] = new int[n];
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            rev[j++] = arr[i];
        }
        printRevArray(rev, n);
    }

    static void printRevArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
