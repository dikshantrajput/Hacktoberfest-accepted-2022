
class puzzle 
{
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    static int eggDrop(int q, int w) 
	{
	    // Your code here
	    int arr[][]=new int[q+1][w+1];
	    for(int i=1; i<=q; i++){
	        arr[i][1]=1;
	        arr[i][0]=0;
	    }
	    for(int j=1; j<=w; j++){
	        arr[1][j]=j;
	    }
	    int res;
	    for(int i=2; i<=q; i++){
	        for(int j=2; j<=w; j++){
	            arr[i][j]=Integer.MAX_VALUE;
	            for(int x=1; x<=j; x++){
	                res=1+Math.max(arr[i-1][x-1],arr[i][j-x]);
	                if(res<arr[i][j]){
	                    arr[i][j]=res;
	                }
	            }
	        }
	    }
	    return arr[q][w];
	}
}