package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {

	var start, end time.Time

	numeros100 := generateRandomNumber(100)
	numeros1000 := generateRandomNumber(1000)
	numeros10000 := generateRandomNumber(10000)
	numeros100000 := generateRandomNumber(1000000)

	fmt.Println("Arreglo de 100 elementos")
	start = time.Now()
	Quicksort(numeros100, 0, len(numeros100)-1)
	end = time.Now()
	fmt.Println("Tiempo de ejecución: ", end.Sub(start))

	fmt.Println("Arreglo de 1000 elementos")
	start = time.Now()
	Quicksort(numeros1000, 0, len(numeros1000)-1)
	end = time.Now()
	fmt.Println("Tiempo de ejecución: ", end.Sub(start))

	fmt.Println("Arreglo de 10000 elementos")
	start = time.Now()
	Quicksort(numeros10000, 0, len(numeros10000)-1)
	end = time.Now()
	fmt.Println("Tiempo de ejecución: ", end.Sub(start))

	fmt.Println("Arreglo de 1000000 elementos")
	start = time.Now()
	Quicksort(numeros100000, 0, len(numeros100000)-1)
	end = time.Now()
	fmt.Println("Tiempo de ejecución: ", end.Sub(start))
}

func generateRandomNumber(size int) []int {
	numeros := make([]int, size)
	// [0, 100)
	for i := 0; i < size; i++ {
		numeros[i] = rand.Intn(100)
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
