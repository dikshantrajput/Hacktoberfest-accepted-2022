import java.util.*;

public class reverseStackUsingRecursion {
    static void reverse(Stack<Integer> s) {
        if (s.isEmpty())
            return;
        int x = s.pop();
        reverse(s);

        ansStack(x, s);
    }

    static void ansStack(int x, Stack<Integer> s) {
        if (s.isEmpty()) {
            s.push(x);
        } else {
            int y = s.pop();
            ansStack(x, s);
            s.push(y);
        }
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        reverse(s);
        System.out.println(s);
    }
}