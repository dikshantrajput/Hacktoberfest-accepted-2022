import java.util.Arrays;
public class ArrAtPos {
	public static void main(String args[])
	{
		int arr[]= {2,4,6,8,10,12};
		System.out.println("Original Array: "+ Arrays.toString(arr));
		int index= 2;
		int element = 5;
		
		for(int i=arr.length-1; i>=index; i--)
		{
			arr[i]=arr[i-1];
		}
		arr[index]=element;
		System.out.println("New Array: "+ Arrays.toString(arr));
		
	}

}
