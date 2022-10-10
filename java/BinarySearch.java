import java.util.Scanner;

class BinarySearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] entry = sc.nextLine().split(" ");
        int search = sc.nextInt();
        int[] numbers = strToInt(entry);
        System.out.println(buscaBinaria(numbers, search));
    }

    public static int buscaBinaria(int[] numbers, int e) {
        int middle;
        int start = 0;
        int end = numbers.length - 1;

        while (start <= end ) {
            middle = (start + end) / 2;
            if (numbers[middle] == e) {
                return middle;
            } else if (numbers[middle] < e) {
                start = middle + 1;
            }
            else if (numbers[middle] > e) {
                end = middle - 1;
            }
            System.out.println(middle);
        }
        return -1;
    }

    public static int[] strToInt(String[] array) {
        int[] numbers = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            numbers[i] = Integer.parseInt(array[i]);
        }
        return numbers;
    }
}