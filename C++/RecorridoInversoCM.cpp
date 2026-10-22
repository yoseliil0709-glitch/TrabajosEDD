#include <iostream>
using namespace std;
int main() {
    int arr[] = {40, 50, 60, 70, 80, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Recorrido inverso: ";
    for(int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}