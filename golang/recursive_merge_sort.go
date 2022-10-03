package main

import "fmt"

func main() {
	arr := []int{11, 14, 3, 8, 18, 17, 43}
	fmt.Println("Before", arr)
	res := MergeSort(arr)
	fmt.Println("After", res)
}

func MergeSort(arr []int) []int {
	length := len(arr)
	if length < 2 {
		return arr
	}
	mid := len(arr) / 2
	left, right := MergeSort(arr[:mid]), MergeSort(arr[mid:])
	return merge(left, right)
}

func merge(left, right []int) []int {
	res := []int{}
	leftIndex, rightIndex := 0, 0
	for i := 0; i < (len(left) + len(right)); i++ {
		if left[leftIndex] < right[rightIndex] {
			res = append(res, left[leftIndex])
			leftIndex++
		} else {
			res = append(res, right[rightIndex])
			rightIndex++
		}
		if leftIndex == len(left) {
			res = append(res, right[rightIndex:]...)
			break
		} else if rightIndex == len(right) {
			res = append(res, left[leftIndex:]...)
			break
		}
	}
	return res
}
