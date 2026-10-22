function merge(a, l, m, r) {
    let n1 = m - l + 1;
    let n2 = r - m;

    let L = new Array(n1);
    let R = new Array(n2);

    for (let i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }

    for (let j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }

    let i = 0;
    let j = 0;
    let k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

function mergeSort(a, l, r) {
    if (l < r) {
        let m = Math.floor((l + r) / 2);
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

let a = [12, 11, 13, 5, 6, 7];

console.log("Antes de ordenar el arreglo: ");
console.log(a.join(" "));

mergeSort(a, 0, a.length - 1);

console.log("Despues de ordenar el arreglo: ");
console.log(a.join(" "));