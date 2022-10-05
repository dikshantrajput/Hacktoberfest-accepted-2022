package main

import (
	"fmt"
)

func binarySearch(arr []int, size int, query int) int {
	low, high := 0, size-1

	for low <= high {
		mid := low + (high-low)/2

		if arr[mid] == query {
			return mid
		} else if arr[mid] > query {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}

	return -1
}

func main() {
	size := 0
	fmt.Printf("Enter the number of elements in the array\n> ")
	if _, err := fmt.Scanf("%d", &size); err != nil {
		panic(err)
	}

	arr := make([]int, size)
	fmt.Printf("Enter the array in increasing order one by one\n")
	for i := 0; i < size; i++ {
		fmt.Printf("%v> ", i+1)
		if _, err := fmt.Scanf("%d", &arr[i]); err != nil {
			panic(err)
		}
		if i > 0 && arr[i] < arr[i-1] {
			panic("array not in increasingly sorted order")
		}
	}
	fmt.Printf("Entered array : %+v\n", arr)

	query := 0
	fmt.Printf("Enter the query to search in the array\n> ")
	if _, err := fmt.Scanf("%d", &query); err != nil {
		panic(err)
	}

	if result := binarySearch(arr, size, query); result == -1 {
		fmt.Printf("Query '%v' not found in the array\n", query)
	} else {
		fmt.Printf("Query '%v' found at place '%v' in the array\n", query, result+1)
	}
}
