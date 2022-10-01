# Python program for implementation of Radix Sort

def countingSort(arr, exp1):
   
    n = len(arr)
   
    output = [0] * (n)
   
    count = [0] * (10)
   
    for i in range(0, n):
        index = (arr[i]/exp1)
        count[int((index)%10)] += 1
   
    for i in range(1,10):
        count[i] += count[i-1]
   
    i = n-1
    while i>=0:
        index = (arr[i]/exp1)
        output[ count[ int((index)%10) ] - 1] = arr[i]
        count[int((index)%10)] -= 1
        i -= 1
   
    i = 0
    for i in range(0,len(arr)):
        arr[i] = output[i]
 
def radixSort(arr):
 
    max1 = max(arr)
 
    exp = 1
    while max1/exp > 0:
        countingSort(arr,exp)
        exp *= 10
 
# Driver code
import random
randomlist = []
for i in range(0,5):
    n = random.randint(1,30)
    randomlist.append(n)
print('Before sorting:', randomlist)

radixSort(randomlist)
print('After sorting:', randomlist)
