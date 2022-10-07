import java.util.Scanner;

public class butterfly_pattern {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no. of rows u want");
        int number = sc.nextInt();

        //for upper traiangular parts
        for(int i=1;i<=number;i++){
            //for printing begining stars
            for(int j=1;j<=i;j++){
                System.out.print("*");
            }

            //for printing middle spaces
            for(int j=1;j<=2*(number-i);j++){
                System.out.print(" ");
            }

            //for printing ending stars
            for(int j=1;j<=i;j++){
                System.out.print("*");
            }
            System.out.println();
        }

        //for lower triangular parts
        for(int i=number;i>=1;i--){
            //for printing begining stars
            for(int j=1;j<=i;j++){
                System.out.print("*");
            }

            //for printing middle spaces
            for(int j=1;j<=2*(number-i);j++){
                System.out.print(" ");
            }

            //for printing ending stars
            for(int j=1;j<=i;j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
