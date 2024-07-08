package main

import "fmt"

type Grafo struct {
	vertices   int
	adyacencia [][]int
}

func nuevoGrafo(vertices int) *Grafo {
	g := &Grafo{
		vertices:   vertices,
		adyacencia: make([][]int, vertices),
	}
	for i := range g.adyacencia {
		g.adyacencia[i] = make([]int, vertices)
	}
	return g
}

func (g *Grafo) agregarArista(src, dest, peso int) {
	g.adyacencia[src][dest] = peso
	g.adyacencia[dest][src] = peso
}

func (g *Grafo) imprimirGrafo() {
	for i := 0; i < g.vertices; i++ {
		fmt.Printf("Nodo %d: ", i)
		for j := 0; j < g.vertices; j++ {
			if g.adyacencia[i][j] > 0 {
				fmt.Printf("%d(%d) ", j, g.adyacencia[i][j])
			}
		}
		fmt.Println()
	}
}

func main() {
	g := nuevoGrafo(5)
	g.agregarArista(0, 1, 2)
	g.agregarArista(0, 4, 1)
	g.agregarArista(1, 2, 3)
	g.agregarArista(1, 3, 4)
	g.agregarArista(2, 3, 5)
	g.agregarArista(3, 4, 6)

	fmt.Println("Representación del grafo:")
	g.imprimirGrafo()
}
