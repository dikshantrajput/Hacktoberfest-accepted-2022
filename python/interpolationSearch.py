def interpolationSearch(arr, lo, hi, x):
	if (lo <= hi and x >= arr[lo] and x <= arr[hi]):
		pos = lo + ((hi - lo) // (arr[hi] - arr[lo]) *
					(x - arr[lo]))
		if arr[pos] == x:
			return pos

		if arr[pos] < x:
			return interpolationSearch(arr, pos + 1, hi, x)

		if arr[pos] > x:
			return interpolationSearch(arr, lo, pos - 1, x)
	return -1

# Driver code
arr = list(map(int,input().split(" ")))
n = len(arr)
x = int(input())#Element to be Searched
index = interpolationSearch(arr, 0, n - 1, x)

if index != -1:
	print("Element found at index", index)
else:
	print("Element not found")
