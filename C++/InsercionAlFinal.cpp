#include <iostream>
using namespace std;

int main() {
    int arr[100] = {11, 21, 31, 41, 51, 61};
    int size = 6;
    int ele = 52;
    arr[size] = ele;
    size++;
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}