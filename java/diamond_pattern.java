import java.util.*;

public class diamond_pattern {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no. of rows u want");
        int number = sc.nextInt();
        for(int i=1;i<=number;i++){
            for(int j=1;j<=number-i;j++){
                System.out.print("  ");
            }
            for(int j=1;j<=2*i-1;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int i=number;i>=1;i--){
            for(int j=1;j<=number-i;j++){
                System.out.print("  ");
            }
            for(int j=1;j<=2*i-1;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
