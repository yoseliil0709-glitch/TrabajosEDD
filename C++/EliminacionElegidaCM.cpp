#include <iostream>
using namespace std;
int main() {
    int arr[] = {11, 21, 31, 41, 51, 61};
    int size = 6;
    int pos = 2; // eliminar el 31
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}