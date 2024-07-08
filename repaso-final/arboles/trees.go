package main

import (
	"fmt"
)

type Nodo struct {
	valor int
	hijos []*Nodo
}

func NuevoNodo(valor int) *Nodo {
	return &Nodo{valor: valor, hijos: []*Nodo{}}
}

func (n *Nodo) AgregarHijo(hijo *Nodo) {
	n.hijos = append(n.hijos, hijo)
}

func (n *Nodo) Buscar(valor int) *Nodo {
	if n.valor == valor {
		return n
	}
	for _, hijo := range n.hijos {
		if encontrado := hijo.Buscar(valor); encontrado != nil {
			return encontrado
		}
	}
	return nil
}

func (n *Nodo) RecorridoPreorden() {
	fmt.Printf("%d ", n.valor)
	for _, hijo := range n.hijos {
		hijo.RecorridoPreorden()
	}
}

func main() {
	raiz := NuevoNodo(1)
	nodo2 := NuevoNodo(2)
	nodo3 := NuevoNodo(3)
	nodo4 := NuevoNodo(4)
	nodo5 := NuevoNodo(5)

	raiz.AgregarHijo(nodo2)
	raiz.AgregarHijo(nodo3)
	nodo2.AgregarHijo(nodo4)
	nodo2.AgregarHijo(nodo5)

	fmt.Println("Recorrido en preorden:")
	raiz.RecorridoPreorden()

	buscado := raiz.Buscar(4)
	if buscado != nil {
		fmt.Printf("\nNodo con valor %d encontrado\n", buscado.valor)
	} else {
		fmt.Println("\nNodo no encontrado")
	}
}
