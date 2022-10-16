import java.util.*;  
class fibonacci {
    static int a = 0, b = 1, c = 0;

    static void printFibonacci(int n) {
        if(n>0){
            c=a+b;
            a=b;
            b=c;
            System.out.print(" " + c);
            printFibonacci(n - 1);
        }
    }
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);  
        int n= sc.nextInt();  
        System.out.print(a + " " + b);
        printFibonacci(n - 2);
        sc.close();
    }
}
