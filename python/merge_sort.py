#Merge Sort Program
def mergeSort(arr):

    if len(arr) > 1:
        a = len(arr)//2
        l = arr[:a]
        r = arr[a:]

        mergeSort(l)
        mergeSort(r) 

        b = c = d = 0
        while b < len(l) and c < len(r):

            if l[b] < r[c]:
                arr[d] = l[b]
                b += 1
            else:
                arr[d] = r[c]
                c += 1
            d += 1

        while b < len(l):
            arr[d] = l[b]
            b += 1
            d += 1

        while c < len(r):

            arr[d] = r[c]
            c += 1
            d += 1


def printList(arr):

    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()
 

# Driver Sample Code

if __name__ == '__main__':
    arr = [0,1,3,5,7,9,2,4,6,8] 
    mergeSort(arr) 
    print("Sorted array is: ")
    printList(arr)
