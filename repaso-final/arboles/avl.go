package main

import (
	"fmt"
)

type NodoAVL struct {
	valor              int
	altura             int
	izquierdo, derecho *NodoAVL
}

func NuevoNodoAVL(valor int) *NodoAVL {
	return &NodoAVL{valor: valor, altura: 1}
}

func Altura(n *NodoAVL) int {
	if n == nil {
		return 0
	}
	return n.altura
}

// RotacionDerecha realiza una rotación simple a la derecha
func RotacionDerecha(y *NodoAVL) *NodoAVL {
	x := y.izquierdo
	T2 := x.derecho

	// Rotar
	x.derecho = y
	y.izquierdo = T2

	// Actualizar alturas
	y.altura = max(Altura(y.izquierdo), Altura(y.derecho)) + 1
	x.altura = max(Altura(x.izquierdo), Altura(x.derecho)) + 1

	return x
}

// RotacionIzquierda realiza una rotación simple a la izquierda
func RotacionIzquierda(x *NodoAVL) *NodoAVL {
	y := x.derecho
	T2 := y.izquierdo

	// Rotar
	y.izquierdo = x
	x.derecho = T2

	// Actualizar alturas
	x.altura = max(Altura(x.izquierdo), Altura(x.derecho)) + 1
	y.altura = max(Altura(y.izquierdo), Altura(y.derecho)) + 1

	return y
}

// FactorEquilibrio obtiene el factor de equilibrio de un nodo
func FactorEquilibrio(n *NodoAVL) int {
	if n == nil {
		return 0
	}
	return Altura(n.izquierdo) - Altura(n.derecho)
}

// Insertar agrega un nuevo nodo al árbol AVL y lo balancea
func (n *NodoAVL) Insertar(valor int) *NodoAVL {
	if n == nil {
		return NuevoNodoAVL(valor)
	}
	if valor < n.valor {
		n.izquierdo = n.izquierdo.Insertar(valor)
	} else if valor > n.valor {
		n.derecho = n.derecho.Insertar(valor)
	} else {
		return n
	}

	n.altura = 1 + max(Altura(n.izquierdo), Altura(n.derecho))

	factor := FactorEquilibrio(n)

	if factor > 1 && valor < n.izquierdo.valor {
		return RotacionDerecha(n)
	}
	if factor < -1 && valor > n.derecho.valor {
		return RotacionIzquierda(n)
	}
	if factor > 1 && valor > n.izquierdo.valor {
		n.izquierdo = RotacionIzquierda(n.izquierdo)
		return RotacionDerecha(n)
	}
	if factor < -1 && valor < n.derecho.valor {
		n.derecho = RotacionDerecha(n.derecho)
		return RotacionIzquierda(n)
	}

	return n
}

func (n *NodoAVL) RecorridoInorden() {
	if n != nil {
		n.izquierdo.RecorridoInorden()
		fmt.Printf("%d ", n.valor)
		n.derecho.RecorridoInorden()
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var raiz *NodoAVL
	raiz = raiz.Insertar(10)
	raiz = raiz.Insertar(20)
	raiz = raiz.Insertar(30)
	raiz = raiz.Insertar(40)
	raiz = raiz.Insertar(50)
	raiz = raiz.Insertar(25)

	fmt.Println("Recorrido inorden del árbol AVL:")
	raiz.RecorridoInorden()
}
