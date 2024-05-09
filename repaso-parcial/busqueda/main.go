package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	var start, end time.Time

	numbers := generateRandomNumber(1000)
	Quicksort(numbers, 0, len(numbers)-1)
	
	fmt.Println("Numero a buscar(linear): ", numbers[5])
	start = time.Now()
	fmt.Println("Posicion del numero: ", linearSearch(numbers, numbers[855]))
	end = time.Now()
	fmt.Println("Tiempo de ejecución: ", end.Sub(start))

	fmt.Println("Numero a buscar(binary): ", numbers[5])
	start = time.Now()
	fmt.Println("Posicion del numero: ", binarySearch(numbers, numbers[855]))
	end = time.Now()
	fmt.Println("Tiempo de ejecución: ", end.Sub(start))
}

func linearSearch(numbers []int, number int) int {
	for i, n := range numbers {
		if n == number {
			return i
		}
	}
	return -1
}

func binarySearch(numbers []int, number int) int {
	low := 0
	high := len(numbers) - 1
	for low <= high {
		mid := (low + high) / 2
		guess := numbers[mid]
		if guess == number {
			return mid
		}
		if guess > number {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return -1
}

func generateRandomNumber(size int) []int {
	numeros := make([]int, size)
	for i := 0; i < size; i++ {
		numeros[i] = rand.Intn(1000)
	}
	return numeros
}

func Quicksort(arr []int, inicio int, fin int) {
	if inicio < fin {
		pivote := Particionar(arr, inicio, fin)
		Quicksort(arr, inicio, pivote-1)
		Quicksort(arr, pivote+1, fin)
	}
}

func Particionar(arr []int, inicio int, fin int) int {
	pivote := arr[fin]
	i := inicio - 1

	for j := inicio; j < fin; j++ {
		if arr[j] < pivote {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[fin] = arr[fin], arr[i+1]
	return i + 1
}
