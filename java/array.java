import java.util.Scanner;

public class array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the size of array");
        int size = sc.nextInt();
        int marks[] = new int[size];
        for(int i=0;i<size;i++){
            System.out.println(marks[i]);
        }

        System.out.println("enter elements of array");
        for(int i=0;i<size;i++){
            int num = sc.nextInt();
            marks[i] = num;
        }

        System.out.println("the size of array is "+marks.length);
        for(int i=0;i<size;i++){
            System.out.println(marks[i]);
        }
    }
}
