import java.util.Arrays;
public class ArrAtEnd{
	public static void main(String args[])
	{
		int arr[]= {2,4,6};
		ArrayList<Integer> list = new ArrayList<>();
		int element =8;
		list.add(element);
// 		int newArr[]=Arrays.copyOf(arr, arr.length+1);
// 		newArr[arr.length]=element;
		
		System.out.println("Original Array: " + Arrays.toString(arr));
		System.out.println("New Array: " +  list);
		
	}
}
