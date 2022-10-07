import java.util.Scanner;

public class calculate_factorial {
    public static int calculateFactorial(int num){
        if(num==0){
            return 1;
        }
        else if(num==1){
            return 1;
        }
        else{
            return num*calculateFactorial(num-1);
        }
    }
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("enter no. ");
        int num = sc.nextInt();
        System.out.println("factorial of "+num+" is "+calculateFactorial(num)); 
    }
    
}
