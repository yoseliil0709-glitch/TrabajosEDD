let arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
console.log("Los elementos del array bidimensiona son: ");
for(let i=0; i<3; i++){
    let fila = "";
    for(let j=0; j<3; j++){
        fila += arr[i][j] + " ";
    }
    console.log(fila);
}