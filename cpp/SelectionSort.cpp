//Selection Sort in C++
#include <iostream>
using namespace std;

void swap(int &a, int &b) {      
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int array[], int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void selectionSort(int array[], int size) {
   int i, j, min;
   for(i = 0; i<size-1; i++) {
      min = i;
      for(j = i+1; j<size; j++){
         if(array[j] < array[min])
            min = j;
      }
         swap(array[i], array[min]);
   }
}
int main() {
    int arr[] = {3, 8, 9, 16, 4, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before Sorting: ";
    display(arr, n);
    selectionSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);
    return 0;
}    