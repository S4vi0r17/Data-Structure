#include <iostream>
using namespace std;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

class MatrizPorColumnas
{
    private:
        int filas, columnas;
        int matriz[MAX_FILAS][MAX_COLUMNAS];

    public:
        void crearMatriz()
        {
            cout << "Ingrese el número de filas: ";
            cin >> filas;
            cout << "Ingrese el número de columnas: ";
            cin >> columnas;

            for (int i = 0; i < filas; ++i)
            {
                for (int j = 0; j < columnas; ++j)
                {
                    cout << "Ingrese el valor para la posición [" << i << "," << j << "]: ";
                    cin >> matriz[i][j];
                }
            }
        }

        void recorrerMatrizPorColumnas()
        {
            cout << "Recorrido por columnas: " << endl;
            for (int j = 0; j < columnas; ++j)
            {
                for (int i = 0; i < filas; ++i)
                {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
        }
};

main()
{
    MatrizPorColumnas matriz;
    matriz.crearMatriz();
    matriz.recorrerMatrizPorColumnas();
}

/*
ALGORITMO MatrizPorColumnas
    ENTERO filas, columnas
    ENTERO matriz[MAX_FILAS][MAX_COLUMNAS]

    PROCEDIMIENTO crearMatriz()
        ESCRIBIR "Ingrese el número de filas: "
        LEER filas
        ESCRIBIR "Ingrese el número de columnas: "
        LEER columnas

        PARA i DESDE 0 HASTA filas - 1 HACER
            PARA j DESDE 0 HASTA columnas - 1 HACER
                ESCRIBIR "Ingrese el valor para la posición [" CONCATENAR i CONCATENAR "," CONCATENAR j CONCATENAR "]: "
                LEER matriz[i][j]
            FIN PARA
        FIN PARA
    FIN PROCEDIMIENTO

    PROCEDIMIENTO recorrerMatrizPorColumnas()
        ESCRIBIR "Recorrido por columnas: "
        PARA j DESDE 0 HASTA columnas - 1 HACER
            PARA i DESDE 0 HASTA filas - 1 HACER
                ESCRIBIR matriz[i][j] CONCATENAR " "
            FIN PARA
            ESCRIBIR NUEVA_LINEA
        FIN PARA
    FIN PROCEDIMIENTO

INICIO
    crearMatriz()
    recorrerMatrizPorColumnas()
FIN

*/
