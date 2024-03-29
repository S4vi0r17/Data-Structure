#include <iostream>
#include <conio.h>

using namespace std;

struct Producto
{
    string codigo;
    string nombre;
    int cantidad;
};

class Fila
{
    FILE *F;
    int N;
    Producto P;

public:
    void crear();
    void recorrer();
};

void Fila::crear()
{
    int i, n;
    F = fopen("productos.txt", "w");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
        cout << "Ingrese la cantidad de productos: ";
        cin >> n;
        i = 0;
        while (i < n)
        {
            cout << "Producto " << i + 1 << endl;
            cout << "Codigo: ";
            cin >> P.codigo;
            cout << "Nombre: ";
            cin >> P.nombre;
            cout << "Cantidad: ";
            cin >> P.cantidad;
            fwrite(&P, sizeof(Producto), 1, F);
            i++;
        }
        fclose(F);
    }
}

void Fila::recorrer()
{
    F = fopen("productos.txt", "r");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    fread(&P, sizeof(P), 1, F);
    int bol = 0;
    cout << "Reporte de productos" << endl;
    while (!feof(F))
    {
        bol++;
        cout << endl
             << endl
             << bol << "Codigo: " << P.codigo << endl;
        cout << "Nombre: " << P.nombre << endl;
        cout << endl
             << endl
             << "Cantidad: " << P.cantidad << endl;
        if (bol % 2 == 0)
        {
            cout << "Presione una tecla para continuar" << endl;
            // cin.get();
        }
        fread(&P, sizeof(P), 1, F);
    }
    fclose(F);
    getch();
}

int menu()
{
    int opc;
    cout << "Menu" << endl;
    cout << "1. Crear archivo" << endl;
    cout << "2. Recorrer archivo" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    return opc;
}

main() {
    int opc;
    Fila fil;
    int i, n;
    opc = menu();
    while (opc != 0)
    {
        switch (opc)
        {
        case 1:
            fil.crear();
            break;
        case 2:
            fil.recorrer();
            break;
        }
        opc = menu();
    }
}