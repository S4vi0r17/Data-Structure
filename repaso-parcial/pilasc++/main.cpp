#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

void push(Node *&stack, int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->next = stack;
    stack = newNode;

    cout << "Value: " << data << endl;
}

main()
{
    Node *stack = nullptr;
    int n1 = 3, n2 = 4;

    push(stack, n1);
    push(stack, n2);
}