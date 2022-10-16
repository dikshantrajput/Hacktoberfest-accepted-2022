import java.util.*;  
public class reverse_of_number {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);  
        int n= sc.nextInt(),r = 0;
        while(n != 0) {
            int x = n % 10;
            r = r * 10 + x;
            n/=10;
        }
        System.out.println(r);
        sc.close();
    }
}
