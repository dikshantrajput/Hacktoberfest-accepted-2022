import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args) {
        int[] arr = { 3, 1, 2, 5, 4 };
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void sort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int correct = arr[i] - 1;
            if (arr[correct] != arr[i]) {
                swap(arr, correct, i);
            } else {
                i++;
            }
        }
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}