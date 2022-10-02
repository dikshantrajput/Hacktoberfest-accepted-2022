def ducth_national_flag( arr, arr_size):   
  low = 0  
  high = arr_size - 1  
  mid = 0  
  while mid <= high:   
    if arr[mid] == 0:   
      arr[low],arr[mid] = arr[mid],arr[low]   
      low = low + 1  
      mid = mid + 1  
    elif arr[mid] == 1:   
      mid = mid + 1  
    else:   
      arr[mid],arr[high] = arr[high],arr[mid]   
      high = high - 1  
  return arr   
      
# Function to print array   
def printArray(arr):   
    for k in arr:   
        print(k,end=" ")   
    print()  
      
# Driver Program   
arr = [0, 1, 0, 1, 1, 2, 0, 1, 2]   
arr_size = len(arr)  
print(" Array before executing the algorithm: "),   
printArray(arr)   
arr = ducth_national_flag(arr, arr_size)   
print("Array after executing the DNFS algorithm: "),   
printArray(arr)  
