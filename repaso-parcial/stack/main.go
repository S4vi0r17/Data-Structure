package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

func main() {
	var stack *Node = nil
	push(&stack, 2)
	push(&stack, 4)
	pop(&stack)
	pop(&stack)
}

func push(stack **Node, data int) {
	var newNode *Node = new(Node)
	newNode.value = data
	newNode.next = *stack
	*stack = newNode

	fmt.Println("Value: ", data)
}

func pop(stack **Node) {
	aux := *stack
	data := aux.value
	*stack = aux.next
	
	fmt.Println("Value deleted: ", data)
}
