# Selection sort in Python

def selectionSort(array, size):
    
    for index in range(size):
        min_index = index
 
        for j in range(index + 1, size):

            if array[j] < array[min_index]:
                min_index = j
        (array[index], array[min_index]) = (array[min_index], array[index])
 
#Sample driver code
arr = [10, -1, -2, 9, -100]

size = len(arr)
print('The array before sorting in ascending order:', arr)

selectionSort(arr, size)
print('The array before sorting in ascending order:', arr)
