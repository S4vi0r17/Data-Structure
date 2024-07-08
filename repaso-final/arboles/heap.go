package main

import (
	"fmt"
)

type Montón struct {
	arr []int
}

// Insertar agrega un nuevo elemento al montón
func (m *Montón) Insertar(valor int) {
	m.arr = append(m.arr, valor)
	m.heapifyUp(len(m.arr) - 1)
}

// Eliminar elimina el elemento raíz del montón
func (m *Montón) Eliminar() int {
	if len(m.arr) == 0 {
		return -1
	}
	root := m.arr[0]
	m.arr[0] = m.arr[len(m.arr)-1]
	m.arr = m.arr[:len(m.arr)-1]
	m.heapifyDown(0)
	return root
}

func (m *Montón) heapifyUp(index int) {
	for m.arr[parent(index)] < m.arr[index] {
		m.swap(parent(index), index)
		index = parent(index)
	}
}

func (m *Montón) heapifyDown(index int) {
	lastIndex := len(m.arr) - 1
	l, r := left(index), right(index)
	childToCompare := 0

	for l <= lastIndex {
		if l == lastIndex {
			childToCompare = l
		} else if m.arr[l] > m.arr[r] {
			childToCompare = l
		} else {
			childToCompare = r
		}

		if m.arr[index] < m.arr[childToCompare] {
			m.swap(index, childToCompare)
			index = childToCompare
			l, r = left(index), right(index)
		} else {
			return
		}
	}
}

func (m *Montón) swap(i1, i2 int) {
	m.arr[i1], m.arr[i2] = m.arr[i2], m.arr[i1]
}

func parent(i int) int {
	return (i - 1) / 2
}

func left(i int) int {
	return 2*i + 1
}

func right(i int) int {
	return 2*i + 2
}

func main() {
	heap := &Montón{}
	heap.Insertar(10)
	heap.Insertar(20)
	heap.Insertar(30)
	heap.Insertar(40)
	heap.Insertar(50)

	fmt.Println("Elemento extraído del montón:", heap.Eliminar())

	fmt.Println("Montón después de eliminación:")
	for _, val := range heap.arr {
		fmt.Printf("%d ", val)
	}
}
