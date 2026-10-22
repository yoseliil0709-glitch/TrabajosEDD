function insertionSort(a) {
    for (let i = 1; i < a.length; i++) {
        let temp = a[i];
        // Mueve los elementos mayores que temp
        // a una posicion mas adelante de su posicion actual
        let j = i - 1;
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

function printArr(a) { // funcion para imprimir el array
    console.log(a.join(" "));
}

// Código para probar
let a = [70, 15, 2, 51, 60];

console.log("Antes de ordenar los elementos del arreglo: ");
printArr(a);

insertionSort(a);

console.log("\nDespues de arreglos los elementos del arreglo son: ");
printArr(a);