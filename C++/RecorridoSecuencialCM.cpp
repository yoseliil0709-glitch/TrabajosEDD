#include <iostream>
using namespace std;

int main() {
    int arr[] = {40, 50, 60, 70, 80, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Recorrido lineal (secuencial): " << endl;
    cout << "Los elementos del array son: ";
    for(int idx = 0; idx < size; idx++) {
        cout << arr[idx] << " ";
    }
    return 0;
}