// Adding Elements in LinkedList
import java.util.*;
public class AddElements 
{
    public static void main(String args[])
	{
		LinkedList<String> ll = new LinkedList<String>();
		ll.add("Adding");
		ll.add("in");
		ll.add("LinkedList");
		ll.add(1, "Elements");  // to add element at a specific positon
		System.out.println(ll);
	}
}
