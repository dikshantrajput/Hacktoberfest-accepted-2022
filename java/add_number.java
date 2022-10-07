import java.util.*;

public class add_number {

    public static int addNumber(int n1,int n2){
        return n1+n2;
    }
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no.");
        int number1 = sc.nextInt();
        int number2 = sc.nextInt();
        int n3 = addNumber(number1,number2);
        System.out.println("the sum of "+number1+" & "+number2+" is "+n3);
    }
}