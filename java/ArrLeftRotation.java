import java.util.Arrays;
public class ArrLeftRot {
	public static void main(String args[])
	{
		int arr[]=new int [] {1,2,3,4,5,6,7,8};
		System.out.println("Original Array: " + Arrays.toString(arr));
		
		
		int first = arr[0];
		for(int i=0;i<arr.length-1;i++)
		{
			arr[i]=arr[i+1];
		}
		arr[arr.length-1]= first;
		System.out.println("Array after Rotation: "+ Arrays.toString(arr));
		
	}
	

}
