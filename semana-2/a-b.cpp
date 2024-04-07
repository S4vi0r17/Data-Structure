#include <iostream>
using namespace std;

const int MAX_TAMANIO = 100;

class ArregloUnidimensional
{
    private:
        int tamanio;
        int arreglo[MAX_TAMANIO];

    public:
        void crearArreglo()
        {
            cout << "Ingrese el tamaño del arreglo: ";
            cin >> tamanio;

            for (int i = 0; i < tamanio; ++i)
            {
                cout << "Ingrese el valor para la posición [" << i << "]: ";
                cin >> arreglo[i];
            }
        }

        void recorrerArreglo()
        {
            cout << "Elementos del arreglo: ";
            for (int i = 0; i < tamanio; ++i)
            {
                cout << arreglo[i] << " ";
            }
            cout << endl;
        }
};

main()
{
    ArregloUnidimensional arreglo;
    arreglo.crearArreglo();
    arreglo.recorrerArreglo();
}
