function bubbleSort(a) {
    let s = a.length;
    // Iterando por todos los elementos del array
    for (let i = 0; i < s; i++) {
        let isSwapped = false;
        // Los ultimos i elementos ya están en su lugar correspondiente
        for (let j = 0; j < s - i - 1; j++) {
            // Intercambiando si el elemento encontrado es mayor que el siguiente
            if (a[j] > a[j + 1]) {
                let temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSwapped = true;
            }
        }
        if (isSwapped == false) {
            break;
        }
    }
}

let a = [15, 16, 11, 13, 14];
console.log("Antes de ordenar los elementos del array son: ");
console.log(a.join(" "));
bubbleSort(a);
console.log("\nDespués de ordenar los elementos del array son: ");
console.log(a.join(" "));