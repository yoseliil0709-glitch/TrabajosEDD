#include <iostream>

using namespace std;

void countingSort(int arr[], int s, int exp){
  int outputArray[s];
  int countArray[10] = {0};

  for (int j = 0; j<s; j++){
    int idx = arr[j] / exp;
    countArray[idx % 10]++;
  }

  for(int i=1; i<10; i++){
    countArray[i] += countArray[i - 1];
  }

  for(int j = s - 1; j >= 0; j--){
    int idx = arr[j] / exp;
    outputArray[countArray[idx % 10] - 1] = arr[j];
    countArray[idx % 10]--;
  }

  for(int j = 0; j < s; j++){
    arr[j] = outputArray[j];
  }
}

void radixSort(int arr[], int s){
    int max1 = arr[0];
    for(int i = 1; i < s; i++){
        if(arr[i] > max1) max1 = arr[i];
    }

    for(int exp = 1; max1 / exp >= 1; exp *= 10){
        countingSort(arr, s, exp);
    }
}

int main(){
    int arr[] = {171, 46, 76, 91, 803, 25, 3, 67};
    int s = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Arreglo antes de ser ordenado: " << endl;
    for(int j = 0; j < s; j++){
        cout << arr[j] << " ";
    }

    radixSort(arr, s);

    cout << "\nArreglo despues de ser ordenado: " << endl;

    for(int j = 0; j < s; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}