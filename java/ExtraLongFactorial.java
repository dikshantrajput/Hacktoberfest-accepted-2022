/* BigInteger is an inbuilt Java class which is used to perform mathematical operations on integers much larger than primitive int data type.
Big Integer class extends Number and implements Comparable interface.
It provides analogues to all of Java's primitive integer operators and all methods from java.lang.Math package.
For finding factorial of such long integers there are many methods in the BigInteger class which simplify the code.
*/

import java.io.*;
import java.util.*;
import java.math.BigInteger;
//importing the BigInteger class from math package
public class Main {
    public static void main(String[] args) {
        System.out.println("Give the value of n: ");
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        BigInteger factorial = new BigInteger("1");
      //since BigInteger is a class we are creating an object of that class, here factorial.
      //factorial is initialised to 1.
        for(int i = 2; i <= N; i++)
        {
            factorial = factorial.multiply(BigInteger.valueOf(i));
        }
      /*the in-built functions used are : "multiply()" and "valueOf()".
      multiply() is a method which returns a big integer value by compution this *value 
      valueOf()  is a method which returns a BigInteger whose value is equivalent to that of the specified long.
      
      */
        System.out.println(factorial);
    }
}
