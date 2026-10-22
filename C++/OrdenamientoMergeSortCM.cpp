#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i += 1;
        } else {
            a[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    while (i < n1) {
        a[k] = L[i];
        i += 1;
        k += 1;
    }

    while (j < n2) {
        a[k] = R[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    // Programa principal
    int a[] = {12, 11, 13, 5, 6, 7};
    int s = sizeof(a) / sizeof(a[0]);

    cout << "Antes de ordenar el arreglo: " << endl;
    for (int j = 0; j < s; j++) {
        cout << a[j] << " ";
    }

    mergeSort(a, 0, s - 1);

    cout << "\nDespues de ordenar el arreglo: " << endl;
    for (int j = 0; j < s; j++) {
        cout << a[j] << " ";
    }

    return 0;
}