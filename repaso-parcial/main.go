package main

import (
	"fmt"
)

func main() {
	arr := []int{64, 34, 25, 12, 22, 11, 90}
	BubbleSort(arr)
	fmt.Println("Sorted array is: ", arr)
}