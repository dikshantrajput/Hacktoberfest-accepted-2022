
# Python Program for the implementation of Bubble sort.

def bubble_sort(array):
    """
    Sorts an array using Bubble Sort.
    O(n^2) Time.
    """
    for i in range(len(array)-1, 0, -1):
        for j in range(i):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    


if __name__ == "__main__":
    arr = [112, 27, 14, -1, -10, 19, -2]
    print("Unsorted Array")
    print(arr)

    bubble_sort(arr)

    print(arr)