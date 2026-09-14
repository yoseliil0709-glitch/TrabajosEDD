let matriz = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
let arr = [];
for(let i=0; i<3; i++){
    for(let j=0; j<3; j++){
        let k = i * 3 + j;
        arr[k] = (matriz[i][j]);
    }
}
console.log("Orden por filas: " + arr.join(" "));