#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {12, 34, 10, 6, 40, 89, 98, 57, 19, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 40;
    sort(arr, arr + size); // OBLIGATORIO ordenar

    int l = 0, h = size - 1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(arr[mid] == target) {
            cout << "Elemento encontrado en posicion: " << mid+1;
            return 0;
        }
        else if(arr[mid] < target) l = mid + 1;
        else h = mid - 1;
    }
    cout << "Elemento no encontrado";
    return 0;
}