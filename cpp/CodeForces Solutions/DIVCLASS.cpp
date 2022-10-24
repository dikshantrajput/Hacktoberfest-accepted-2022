/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scan=new Scanner(System.in);
		int T=scan.nextInt();
		while(T-->0)
		{
		    int N=scan.nextInt();
		    int a[]=new int[N];
		    HashSet<Integer> hs=new HashSet<Integer>();
    		    for(int i=0;i<N;i++)
    		    {
    		        a[i]=scan.nextInt();
    		        hs.add(a[i]);
    		    }
		    if(N<12)
		    {
		        System.out.println("no");
		    }
		    else
		    {
		        if(hs.size()>12)
		            System.out.println("no");
		        else
		            System.out.println("yes");
		    }
		}
	}
}
