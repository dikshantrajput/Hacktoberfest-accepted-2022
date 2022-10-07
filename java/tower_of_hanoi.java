import java.io.*;
import java.math.*;
import java.util.*;

class tower_of_hanoi {
    static void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
    {
        if (n == 0) {
            return;
        }
        towerOfHanoi(n - 1, fromRod, auxRod, toRod);
        System.out.println("Move disk " + n + " from rod " + fromRod + " to rod " + toRod);
        towerOfHanoi(n - 1, auxRod, toRod, fromRod);
    }
 
    public static void main(String args[])
    {
        int x = 3;
        towerOfHanoi(x, 'X', 'Y', 'Z');
    }
}