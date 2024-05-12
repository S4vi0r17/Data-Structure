#include <iostream>

using namespace std;

struct Nodo
{
    int value;
    Nodo *next;
};

void insert(Nodo *&, int);

int main()
{
    Nodo *list = NULL;

    int data = 5;

    insert(list, 5);

    return 0;
}

void insert(Nodo *&list, int n)
{
    Nodo *newNodo = new Nodo();
    newNodo->value = n;

    Nodo *aux1 = list;
    Nodo *aux2;

    while (aux1 != NULL && aux1->value < n)
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (list == aux1)
    {
        list = newNodo;
    }
    else
    {
        aux2->next = newNodo;
    }

    newNodo->next = aux1;

    cout << "Data: " << n << endl;
}
