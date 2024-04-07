#include <iostream>
using namespace std;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

class ModificarMatriz {
    private:
        int filas, columnas;
        int matriz[MAX_FILAS][MAX_COLUMNAS];

    public:
        void mostrarMatriz() {
            cout << "Matriz actual:" << endl;
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
        }

        void adicionarFila() {
            cout << "Ingrese los elementos de la nueva fila:" << endl;
            for (int j = 0; j < columnas; ++j) {
                cout << "Elemento para la columna " << j << ": ";
                cin >> matriz[filas][j];
            }
            filas = filas + 1;
        }

        void adicionarColumna() {
            cout << "Ingrese los elementos de la nueva columna:" << endl;
            for (int i = 0; i < filas; ++i) {
                cout << "Elemento para la fila " << i << ": ";
                cin >> matriz[i][columnas];
            }
            columnas = columnas + 1;
        }

        void iniciar() {
            cout << "Ingrese el número de filas: ";
            cin >> filas;
            cout << "Ingrese el número de columnas: ";
            cin >> columnas;

            cout << "Ingrese los elementos de la matriz:" << endl;
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    cout << "Elemento para la fila " << i << " y columna " << j << ": ";
                    cin >> matriz[i][j];
                }
            }

            mostrarMatriz();

            adicionarFila();
            adicionarColumna();

            mostrarMatriz();
        }
};

main() {
    ModificarMatriz modMatriz;
    modMatriz.iniciar();
}
