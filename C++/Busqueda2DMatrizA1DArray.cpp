#include <iostream>
using namespace std;
int main() {
    int r=3, c=3;
    int TwoDArr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int arr[9];
    int k=0;
    for(int x=0; x<r; x++) {
        for(int y=0; y<c; y++) {
            k = x * c + y;
            arr[k] = TwoDArr[x][y];
        }
    }
    for(int i=0; i<9; i++) cout << arr[i] << " ";
    return 0;
}