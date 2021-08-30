/**
 * @file Tarea Extraclase 1.cpp
 * @author Gonzalo Acuña M
 * @date 29/5/2021
 * @brief QuickSort Implementation
 *
 */

#include <iostream>
#include <vector>
#include <sstream>
#include "fstream"

using namespace std;


/**
 * @brief Ejecución Ordenamiento Quicksort
 * @param numeros, limite_der, limite_izq
 * @return None
 */
void QuicksortAuxiliar(vector<int> &numeros, int limite_izq, int limite_der){
    //Variables para calcular los límites
    int izq = limite_izq;
    int der = limite_der;
    int pivote = numeros[(izq + der)/2];
    int temporal;
    do {
        while (numeros[izq]<pivote && izq < limite_der){
            ++izq;
        }
        while (pivote<numeros[der] && der > limite_izq){
            --der;
        }
        if (izq <= der){
            temporal = numeros[izq];
            numeros[izq] = numeros[der];
            numeros[der] = temporal;
            ++izq;
            --der;

        }
    } while (izq <= der);
    if (limite_izq < der){
        QuicksortAuxiliar(numeros, limite_izq, der);
    }
    if (limite_der > izq){
        QuicksortAuxiliar(numeros, izq, limite_der);
    }

}
/**
 * @brief Envío de QuickSort con parámetros
 * @param numeros
 * @return None
 */
void Quicksort(vector<int> &numeros){
    QuicksortAuxiliar(numeros, 0, numeros.size() - 1);

}
/**
 * @brief Imprime datos en consola
 * @param numeros
 * @return None
 */
void Print(const vector<int> &numeros){
    const int nNumeros = numeros.size();
    for (int ax = 0; ax < nNumeros; ++ax){
        cout << numeros[ax] << ' ';
    }
}
/**
 * @brief Escribe el nuevo orden en otro archivo
 * @param numeros
 * @return None
 */
void PagedArray(vector<int>(numeros)){
    //Declara el nombre del archivo
    ofstream archivo_resultado;
    //Abre el archivo definido
    archivo_resultado.open("archivoresuelto.txt",ios::out);
    //Condición por si no se puede abrir el archivo
    if(archivo_resultado.fail()){
        cout <<"No se pudo abrir el archivo";
        exit(1);
    }
    //Bucle para colocar los numeros
    for (int i = 0; i < numeros.size(); ++i) {
        archivo_resultado <<numeros[i]<<endl;

    }
    //Cierra el archivo
    archivo_resultado.close();
}
/**
 * @brief Lee los numeros del primer archivo
 * @param numeros
 * @return None
 */
void Read(vector<int> &numeros){
    //Define el primer archivo
    ifstream archivo;
    //abre el archivo definido
    archivo.open("archivo.txt");
    //Lee los numeros y los añade a la variable
    if (archivo){
        double num;
        while (archivo>>num){
            numeros.push_back(num);
        }
    }
}
/**
 * @brief Función principal
 * @param numeros
 * @return 0
 */
int main() {
    //Variable donde se almacenan los numeros
    vector<int> numeros;
    //Llama la función "Read" para leer los numeros del primer archivo
    Read(numeros);
    //Imprime el primer orden de los numeros
    Print(numeros);
    cout << endl;
    //Llama la función para ordenar los numeros con el método "Quick Sort"
    Quicksort(numeros);
    //Imprime los numeros ordenados
    Print(numeros);
    //Llama a la función para copiar el nuevo orden de los valores
    PagedArray(numeros);
    cout << endl;
    return 0;
}



