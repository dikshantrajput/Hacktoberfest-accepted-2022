import java.util.*;
public class IteratingLinkedList 
{
    public static void main(String args[])
	{
		LinkedList<String> ll = new LinkedList<String>();
		ll.add("Adding");
		ll.add("in");
		ll.add("LinkedList");
		ll.add(1, "Elements"); 
		// Using the get method and for loop
		for(int i=0; i<ll.size(); i++)
		{
		    System.out.println(ll.get(i) + " ");
		}
		//Using the for loop
		for (String str : ll)
		{
            System.out.println(str + " ");
		}
	}
}
