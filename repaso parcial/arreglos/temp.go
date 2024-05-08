package main

import (
	"fmt"
)

var HolaMundo string = "Hola Mundo"

func Multiplicacion() {
	// var arr [5]int = [5]int{1, 2, 3, 4, 5}
	arr := [...]int{1, 2, 3, 4, 5} // don't want to specify the size
	mult := 1

	for i := 0; i < len(arr); i++ {
		mult *= arr[i]
	}

	fmt.Println("Multiplicación de los elementos del arreglo:", mult)
}
