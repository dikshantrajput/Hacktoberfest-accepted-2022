import java.util.Arrays;
public class ArrAtEnd{
	public static void main(String args[])
	{
		int arr[]= {2,4,6};
		int element =8;
		int newArr[]=Arrays.copyOf(arr, arr.length+1);
		newArr[arr.length]=element;
		
		System.out.println("Original Array: " + Arrays.toString(arr));
		System.out.println("New Array: " +  Arrays.toString(newArr));
		
	}
}
