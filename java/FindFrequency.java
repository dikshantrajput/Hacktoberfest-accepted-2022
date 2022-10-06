import java.util.*;

public class FindFrequency {
    /**
     * Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.
     *
     * Example 1:
     * Input:
     * N = 5
     * vector = {1, 1, 1, 1, 1}
     * X = 1
     * Output:
     * 5
     * Explanation: Frequency of 1 is 5.
     *
     * */

    public static void main(String[] args){
        FindFrequency ff = new FindFrequency();
        int[] A = {1,1,1};
        int result = ff.findFrequency(A, 1);
        System.out.println(result);
    }


    int findFrequency(int A[], int x){
        int count = 0;
        for(int i = 0; i < A.length; i++){
            if(A[i] == x){
                count++;
            }
        }
        return count;
    }
}
