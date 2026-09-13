let arr = [40, 50, 60, 70, 80, 90];
console.log("Recorrido inverso: ");
let resul = "";
for(let i = arr.length - 1; i >= 0; i--){
    resul += arr[i] + " ";
}
console.log(resul);
