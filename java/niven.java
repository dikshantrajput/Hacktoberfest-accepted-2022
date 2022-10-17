import java.util.*;
class niven
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no.");
        int n=sc.nextInt();
        int s=0;
        while(n!=0)
        {
            int d=n%10;
            s=s+d;
            n/=10;
        }
        if(n%s==0)
        {
            System.out.println("Niven no.");
        }
        else
        {
            System.out.println("Not niven no.");
        }
    }
}

        
        