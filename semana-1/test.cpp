#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
// #include "fstram" // Error: fstram no existe

struct PRODUCTO
{
    char Cod[10];
    char Nombre[10];
    int Cantidad;
};

class Fila
{
    FILE *F;
    int N;
    PRODUCTO P;
} Public void crear();
void recorrer();

void FILA::crear()
{
    int i, n;
    F = open("PRODUCTO.txt", "w");
    if (F == NULL)
    {
        cout << "No se puede abrir el archivo" exit(1);
        cout << "Numero de Productos que desea ingresar? ";
        cin >> n;
        i = 0;
        while (i < n)
        {
            cout << "\n Producto No " << i = i + 1 << endl;
            cout << "\nIngrese el Codigo: ";
            cin >> P.Cod;
            cout << "\nIngrese el Nombre: ";
            cin >> P.Nombre;
            cout << "\nIngrese la Cantidad de Productos: ";
            cin >> P.Cantidad;
            Fwrite(&P, sizeof(P), 1, F);
            i++;
        }
        fclose(F);
    }
