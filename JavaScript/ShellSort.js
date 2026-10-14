class ShellShort {
    static displayArr(imputArr) {
        console.log(imputArr.join(" "));
    }

    sort(imputArr) {
        let size = imputArr.length;
        let gapSize = Math.floor(size / 2);

        while (gapSize > 0) {
            for (let j = gapSize; j < size; j++) {
                let val = imputArr[j];
                let k = j;

                while (k >= gapSize && imputArr[k - gapSize] > val) {
                    imputArr[k] = imputArr[k - gapSize];
                    k = k - gapSize;
                }
                imputArr[k] = val;
            }
            gapSize = Math.floor(gapSize / 2);
        }
        return 0;
    }
}

let imputArr = [36, 34, 43, 11, 15, 20, 28, 45];

console.log("Arreglo antes de ser ordenado: ");
ShellShort.displayArr(imputArr);

let obj = new ShellShort();
obj.sort(imputArr);

console.log("Arreglo despues de ser ordenado: ");
ShellShort.displayArr(imputArr);