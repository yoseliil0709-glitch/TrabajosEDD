def selection(a): #funcion para implementar el algoritmo de seleccion
    for i in range(len(a)): #recorre todo el arreglo
        small = i #indice del elemento mas pequeño
        for j in range(i+1, len(a)): #encuentra el elemento mas pequeño del arreglo
            if a[small] > a[j]: #compara el elemento mas pequeño con el siguiente
                small = j #actualiza el indice del elemento mas pequeño
        #intercambia el elemento mas pequeño con el primer elemento
        a[i], a[small] = a[small], a[i] #intercambia los elementos

def printArr(a): #funcion para imprimir el array
    for i in range(len(a)): #recorre todo el arreglo
        print(a[i], end=" ") #imprime el elemento

a = [65, 26, 13, 23, 12] #arreglo desordenado

print("Arreglo antes de ser ordenado: ")
printArr(a)

selection(a)

print("\nArreglo despues de ser ordenado: ")
printArr(a)