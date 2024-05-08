package main

import (
	"fmt"
)

func main() {

	var matrix [3][3]int

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			fmt.Print("Ingrese un valor: [", i, "][", j, "]: ")
			fmt.Scanf("%d\n", &matrix[i][j])
		}
	}

	fmt.Println("Recorrido por filas")
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			fmt.Print(matrix[i][j], " ")
		}
		fmt.Println()
	}

	fmt.Println("Recorrido por columnas")
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			fmt.Print(matrix[j][i], " ")
		}
		fmt.Println()
	}
}
