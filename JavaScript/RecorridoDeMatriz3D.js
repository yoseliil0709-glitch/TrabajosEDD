let matriz3D = [
    [[1,2], [3,4]],
    [[5,6], [7,8]]
];

console.log("Recorrido matriz 3D: ");
for(let i=0; i<2; i++){
    for(let j=0; j<2; j++){
      for(let k=0; k<2; k++){
        console.log(`matriz[${i}][${j}][${k}] = ${matriz3D[i][j][k]}`);
         }
    }
}