let arr = [12, 34, 10, 6, 40, 89, 98];
let target = 40;
arr.sort((a,b) => a-b);

let l = 0, h = arr.length - 1;
let enco = false;

while(l <= h){
    let mid = Math.floor(l + (h - 1) / 2);
    if(arr[mid] == target){
    console.log(`Elemento encontrado en la posición: ${mid+1}`);
    enco = true;
    break;
}else if(arr[mid] < target){
    l = mid + 1;
}else {
    h = mid - 1;
}
}
if(!enco) console.log("Elemento no encontrado");
 
