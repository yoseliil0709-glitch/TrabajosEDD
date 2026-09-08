#include <iostream>
using namespace std;
int main() {
    int arr[] = {12, 34, 10, 6, 40, 89, 98};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 40;
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            cout << "Elemento encontrado en posicion: " << i+1;
            return 0;
        }
    }
    cout << "Elemento no encontrado";
    return 0;
}