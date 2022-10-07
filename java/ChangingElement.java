// Changing Elements in LinkedList
import java.util.*;
public class ChangingElement 
{
    public static void main(String args[])
	{
		LinkedList<String> ll = new LinkedList<String>();
		ll.add("Adding");
		ll.add("in");
		ll.add("LinkedList");
		ll.add(1, "Elements");  // to add element at a specific positon
		System.out.println("Initial Linked List : " + ll);
		
		ll.set(0, "Changing"); //changing element at specific positon
		
		System.out.println("Updated Linked List : " + ll);
	}
}
