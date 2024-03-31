#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Producto
{
    char codigo[10];
    char nombre[10];
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
    void buscar();
};

void Fila::crear()
{
    int i, n;
    F = fopen("productos.txt", "w");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
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
        fwrite(&P, sizeof(P), 1, F);
        i++;
    }
    fclose(F);
}

void Fila::recorrer()
{
    F = fopen("productos.txt", "r");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    int bol = 0;
    cout << "Reporte de productos" << endl;
    while (fread(&P, sizeof(P), 1, F) == 1)
    {
        bol++;
        cout << endl
             << endl
             << bol << " Codigo: " << P.codigo << endl;
        cout << "Nombre: " << P.nombre << endl;
        cout << "Cantidad: " << P.cantidad << endl;
        if (bol % 2 == 0)
        {
            cout << "Presione una tecla para continuar" << endl;
        }
    }
    fclose(F);
    getch();
}

void Fila::buscar(){
    F = fopen("productos.txt", "r");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    fread(&P, sizeof(P), 1, F);
    int bol = 0;
    char codigo[10] = "7AB01";
    cout << "Reporte de productos" << endl;
    while (!feof(F))
    {
        if (codigo == P.codigo)
        {
            bol++;
            cout << endl
                 << endl
                 << bol << " El producto de codigo " << codigo << " se ha encontrado" << P.codigo << endl;
            cout << "Nombre: " << P.nombre << endl;
            cout << "Cantidad: " << P.cantidad << endl;
        } else {
            cout << "No se encontro el producto con el codigo " << codigo << endl;
        }
        if (bol % 2 == 0)
        {
            cout << "Presione una tecla para continuar" << endl;
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
    cout << "3. Buscar producto" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    return opc;
}

main()
{
    int opc;
    Fila fil;
    int i, n;
    opc = menu();
    while (opc != 4)
    {
        switch (opc)
        {
        case 1:
            fil.crear();
            break;
        case 2:
            fil.recorrer();
            break;
        case 3:
            fil.buscar();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        opc = menu();
    }
}