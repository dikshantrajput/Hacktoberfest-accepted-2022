import java.util.Scanner;

public Armstrong {
    public static void main(String[] args) {
        //To find Armstrong Number between two given number.
        //eg: 153 -> 1 5 3 (take cube of each digit)
        //1*1*1 + 5*5*5 + 3*3*3 (add them)
        //1 + 125 + 27 = 153 (the result is number itself, Hence its an Armstrong Number)
        //-------------------------------
        Scanner in = new Scanner(System.in);
        System.out.print("Enter First Input: ");
        int first = in.nextInt();
        System.out.print("Enter Second Input: ");
        int second = in.nextInt();
         for(int i = first; i <= second; i++) {
             int value = i;
             int sum = 0;

             while (value > 0) {
                 int remainder = value % 10;
                 sum = sum + (remainder * remainder * remainder);
                 value = value / 10;
             }

             if (sum == i) {
                 System.out.println(sum);
             }
         }
    }
}
