#include <iostream>

using namespace std;

int main()
{
    int numero = 10;
    int *puntero = &numero;

    cout << "Valor de la variable original: " << numero << endl;
    cout << "Valor del contenido al que apunta el puntero: " << *puntero << endl;

    *puntero = 20; // Modifica el valor de la variable original a través del puntero
    cout << "Valor de la variable original después de modificar: " << numero << endl;


    int *puntero = nullptr;
    if (puntero == nullptr)
    {
        cout << "El puntero es nulo." << endl;
    }


    int arr[3] = {10, 20, 30};
    int *ptr = arr;

    cout << *ptr << endl;       // Imprime 10
    cout << *(ptr + 1) << endl; // Imprime 20
}
