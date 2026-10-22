let arr = [12, 34, 10, 6, 40, 89, 98];
let target = 40;
for(let i = 0; i < arr.length; i++){
    if(arr[i] == target){
        console.log(`Elemento encontrado en la posición: ${i+1}`);
    break;
    }
}