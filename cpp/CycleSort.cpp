#include <iostream>
using namespace std;

void swap(int nums[], int start, int end) {
    int temp = nums[start];
    nums[start]= nums[end];
    nums[end] = temp;
}

void cyclicSort(int nums[], int size) {
    int index = 0;
    while(index < size) {
        int correct = nums[index] - 1;
        if(nums[index] != nums[correct]) {
            swap(nums, index, correct);
        }
        else {
            index++;
        }
    }
}

int main() {
    int size;
    cout << "Enter size of the array: " << endl;
    cin >> size;
    int nums[size];
    cout << "Enter enements of array: ";
    for(int i =0; i < size; i++) {
        cin >> nums[i];
    }

    cyclicSort(nums, size);
    cout << "Sorted array: ";

    for(int i =0; i < size; i++) {
        cout << nums[i] << " ";
    }
}
