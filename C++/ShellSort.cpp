#include <iostream>
using namespace std;

class ShellShort {
public:
    static void displayArr(int imputArr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << imputArr[i] << " ";
        }
        cout << endl;
    }

    int sort(int imputArr[], int size) {
        int gapSize = size / 2;

        while (gapSize > 0) {
            for (int j = gapSize; j < size; j++) {
                int val = imputArr[j];
                int k = j;

                while (k >= gapSize && imputArr[k - gapSize] > val) {
                    imputArr[k] = imputArr[k - gapSize];
                    k = k - gapSize;
                }
                imputArr[k] = val;
            }
            gapSize = gapSize / 2;
        }
        return 0;
    }
};

int main() {
    int imputArr[] = {36, 34, 43, 11, 15, 20, 28, 45};
    int size = sizeof(imputArr) / sizeof(imputArr[0]);

    cout << "Arreglo antes de ser ordenado: " << endl;
    ShellShort::displayArr(imputArr, size);

    ShellShort obj;
    obj.sort(imputArr, size);

    cout << "Arreglo despues de ser ordenado: " << endl;
    ShellShort::displayArr(imputArr, size);

    return 0;
}