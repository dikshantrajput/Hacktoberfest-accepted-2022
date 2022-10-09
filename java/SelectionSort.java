import java.util.Arrays;


class Sorting{

    public static int[] selectionSort(int[] array, int nElements){
        //same as the bubble sort but the process differce
        for(int i=0; i<nElements-1; i++){ // iterate through passes
            int minIndex = i; //take the first index as the minIndex
            for(int j=i+1; j<nElements; j++){
                if(array[minIndex]>array[j]){
                    minIndex = j;
                }
            }
            if(minIndex != i){
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
        return array;
    }
}


public class SelectionSort {
    public static void main(String[] args) {
        int[] testArray = {12, 5, 63, 47, 12, 4};

        Sorting sortObj = new Sorting();


        int[] selectionSortedArray = sortObj.selectionSort(testArray, testArray.length);
        for(int i=0; i< selectionSortedArray.length; i++){
            System.out.print(" "+selectionSortedArray[i]);
        }


    }
}
