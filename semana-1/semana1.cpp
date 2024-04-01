#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring> // Add this line

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
    void eliminar();
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
    fread(&P, sizeof(P), 1, F);
    int bol = 0;
    cout << "Reporte de productos" << endl;
    while (!feof(F))
    {
        bol++;
        cout << endl
             << endl
             << bol << " Codigo " << P.codigo;
        cout << "\nNombre: " << P.nombre << endl;
        cout << endl
             << endl
             << "Cantidad: " << P.cantidad;
        if (bol % 2 == 0)
        {
            cout << "Presione una tecla para continuar" << endl;
        }
        fread(&P, sizeof(P), 1, F);
    }
    fclose(F);
    getch();
}

void Fila::buscar()
{
    F = fopen("productos.txt", "r");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    char codigo[10];
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigo;
    fread(&P, sizeof(P), 1, F);
    int bol = 0;
    bool encontrado = false;
    while (!feof(F))
    {
        bol++;
        if (strcmp(codigo, P.codigo) == 0)
        {
            encontrado = true;
            cout << endl
                 << "El producto con el codigo " << codigo << " se ha encontrado" << endl;
            cout << "Nombre: " << P.nombre << endl;
            cout << "Cantidad: " << P.cantidad << endl;
            break;
        }
        fread(&P, sizeof(P), 1, F);
    }
    if (!encontrado)
    {
        cout << "No se ha encontrado el producto con el codigo " << codigo << endl;
    }
    fclose(F);
    getch();
}

// 7AB01
// 8AB01

void Fila::eliminar()
{
    FILE *G;
    F = fopen("productos.txt", "r");
    if (F == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    G = fopen("PTemp.txt", "w");
    if (G == NULL)
    {
        cout << "Error al abrir el archivo temporal" << endl;
        exit(1);
    }
    char codigo[10] = "8AB01";
    fread(&P, sizeof(P), 1, F);
    int bol = 0;
    bool encontrado = false;
    while (!feof(F))
    {
        bol++;
        if (strcmp(codigo, P.codigo) != 0)
        {
            fwrite(&P, sizeof(P), 1, G);
        }
        else
        {
            encontrado = true;
        }
        fread(&P, sizeof(P), 1, F);
    }
    fclose(F);
    fclose(G);
    int rem;
    rem = remove("productos.txt");
    cout << endl
         << "Se elimino el registro pedido";
    int ren;
    ren = rename("PTemp.txt", "productos.txt");
    cout << endl
         << "Se renombro el archivo";
    if (!encontrado)
    {
        cout << endl
             << "No existe el codigo 8AB01" << endl;
    }
    getch();
}

int menu()
{
    int opc;
    cout << "Menu" << endl;
    cout << "1. Crear archivo" << endl;
    cout << "2. Recorrer archivo" << endl;
    cout << "3. Buscar producto" << endl;
    cout << "4. Eliminar producto" << endl;
    cout << "5. Salir" << endl;
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
    while (opc != 5)
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
            fil.eliminar();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        opc = menu();
    }
}