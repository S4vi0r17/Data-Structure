package main

import (
	"fmt"
)

type Nodo struct {
	valor              int
	izquierdo, derecho *Nodo
}

func NuevoNodo(valor int) *Nodo {
	return &Nodo{valor: valor}
}

func (n *Nodo) Insertar(valor int) {
	if valor < n.valor {
		if n.izquierdo == nil {
			n.izquierdo = NuevoNodo(valor)
		} else {
			n.izquierdo.Insertar(valor)
		}
	} else {
		if n.derecho == nil {
			n.derecho = NuevoNodo(valor)
		} else {
			n.derecho.Insertar(valor)
		}
	}
}

func (n *Nodo) Buscar(valor int) *Nodo {
	if n == nil || n.valor == valor {
		return n
	}
	if valor < n.valor {
		return n.izquierdo.Buscar(valor)
	}
	return n.derecho.Buscar(valor)
}

func (n *Nodo) RecorridoInorden() {
	if n != nil {
		n.izquierdo.RecorridoInorden()
		fmt.Printf("%d ", n.valor)
		n.derecho.RecorridoInorden()
	}
}

func main() {
	raiz := NuevoNodo(5)
	raiz.Insertar(3)
	raiz.Insertar(8)
	raiz.Insertar(1)
	raiz.Insertar(4)

	fmt.Println("Recorrido inorden:")
	raiz.RecorridoInorden()

	buscado := raiz.Buscar(4)
	if buscado != nil {
		fmt.Printf("\nNodo con valor %d encontrado\n", buscado.valor)
	} else {
		fmt.Println("\nNodo no encontrado")
	}
}
