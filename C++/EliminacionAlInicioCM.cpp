#include <iostream>
using namespace std;
int main() {
    int arr[] = {11, 21, 31, 41, 51, 61};
    int size = 6;
    for(int i = 0; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}