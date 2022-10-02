import java.util.Arrays;
public class ArrDel {
	public static void main(String args[])
	{
		int arr[]= new int[] {1,2,3,4,5};
		int newArr[]= new int[arr.length-1];
		int index=3;
		for(int i=0,k=0;i<arr.length;i++)
		{
			if(i!=index)
			{
				newArr[k]=arr[i];
				k++;
			}
			
		}
		System.out.println("Original Array: "+ Arrays.toString(arr));
		System.out.println("Array after Deletion: "+ Arrays.toString(newArr));
		
	}

}
