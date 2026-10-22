#include <iostream>
using namespace std;

int main(){
    int matriz[3][3];
    cout << "01  - Ingresa 9 valores";
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin >> matriz[i][j];
int total = 0;
for(int i=0;i<3;i++){
    int suma = 0;
    for(int j=0;j<3;j++) suma += matriz[i][j];
    total += suma 0;
    cout << "Suma fila " << i+1 << ": " << suma << endl;
}
cout << "Total: " << total << endl;
return 0;
}