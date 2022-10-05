import java.util.*;

class Stack{
    static final int MAX=5;
    int top;
    int[] arr = new int[MAX];
    
    Stack(){
        top=-1;
    }
    boolean isEmpty(){
        if(top<0){
            return true;
        }
        return false;
    }
    boolean isFull(){
        if(top>=MAX-1){
            return true;
        }
        return false;
    }
    void push(int x){
        if(isFull()){
            System.out.println("Stack Overflow...");
        }
        top++;
        arr[top]=x;
        System.out.println(x+" has been pushed in Stack...");
    }
    int pop(){
        if(isEmpty()){
            System.out.println("Stack Underflow...");
        }
        int temp=arr[top];
        top--;
        return temp;
    }
    int peek(){
        if(isEmpty()){
            System.out.println("Stack Underflow...");
        }
        int temp=arr[top];
        return temp;
    }
    void show(){
        int i=top;
        if(isEmpty()){
            System.out.println("Stack is Empty...");
        }
        while(i>=0){
            System.out.print(arr[i]+" ");
            i--;
        }
        System.out.println();
    }
}


class HelloWorld {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        Stack s = new Stack();
        int choice;
        do{
            System.out.println("Enter 1 for push");
            System.out.println("Enter 2 for pop");
            System.out.println("Enter 3 for peek");
            System.out.println("Enter 4 for display");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice){
                case 1:
                    System.out.print("Enter the element: ");
                    int x = sc.nextInt();
                    s.push(x);
                    break;
                case 2:
                    System.out.println("Popped Item: "+s.pop());
                    break;
                case 3:
                    System.out.println("Peeked Item: "+s.pop());
                    break;
                case 4:
                    System.out.print("Current Stack: ");
                    s.show();
                    break;
                default:
                    System.out.print("Wrong input");
            }
        }while(choice>=1 && choice<=4);
    }
}
