#include <iostream>
using namespace std;

int main() {
    int arr[100] = {11, 21, 31, 41, 51, 61};
    int size = 6;
    int ele = 52;
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = ele;
    size++;
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}