package main

type Nodo struct {
	valor         int
	izquierdo     *Nodo
	derecho       *Nodo
	hiloIzquierdo bool
	hiloDerecho   bool
}
