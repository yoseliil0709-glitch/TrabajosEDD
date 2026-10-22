#include <iostream>
using namespace std;

void selection(int a[], int n) { //funcion para implementar el algoritmo de seleccion
    for (int i = 0; i < n; i++) { //recorre todo el arreglo
        int small = i; //indice del elemento mas pequeño
        for (int j = i+1; j < n; j++) { //encuentra el elemento mas pequeño del arreglo
            if (a[small] > a[j]) { //compara el elemento mas pequeño con el siguiente
                small = j; //actualiza el indice del elemento mas pequeño
            }
        }
        //intercambia el elemento mas pequeño con el primer elemento
        int temp = a[i];
        a[i] = a[small];
        a[small] = temp; //intercambia los elementos
    }
}

void printArr(int a[], int n) { //funcion para imprimir el array
    for (int i = 0; i < n; i++) { //recorre todo el arreglo
        cout << a[i] << " "; //imprime el elemento
    }
}

int main() {
    int a[] = {65, 26, 13, 23, 12}; //arreglo desordenado
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Arreglo antes de ser ordenado: " << endl;
    printArr(a, n);

    selection(a, n);

    cout << "\nArreglo despues de ser ordenado: " << endl;
    printArr(a, n);

    return 0;
}