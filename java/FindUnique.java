public class FindUnique {
    public static void main(String[] args) {
        int[] arr = { 1,2,2,1,4,5,5,30,4};
        UniqueElement(arr,9);
    }
    static void UniqueElement(int arr[] , int size){
        int ans = 0;
        for(int i = 0;i<size ;i++){
            ans = ans^arr[i];
        }
        System.out.println(ans);
    }
}
