package main

import (
	"fmt"
	"github.com/S4vi0r17/Data-Structure/sorting_algorithms"
)

func main() {
	arr := []int{64, 34, 25, 12, 22}
	sorting_algorithms.QuickSort(arr)
	fmt.Println("Sorted array is: ", arr)
}