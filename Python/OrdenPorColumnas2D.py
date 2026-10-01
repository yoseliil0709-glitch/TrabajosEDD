# Implementacion por COLUMNAS en Python
r = 3; c = 3
arr = [0] * r * c

TwoDArr = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]]

# Almacenar elementos en un array unidimensional ordenados por COLUMNAS
k = 0
for y in range(c): # primero columnas
    for x in range(r): # luego filas
        arr[k] = TwoDArr[x][y]
        k = k + 1

print("Los elementos del array bidimensional son: ")
for row in TwoDArr:
    for ele in row:
        print(ele, end=" ")
    print()

print("\nLos elementos del array unidimensional por columnas son: ")
for i in range(r * c):
    print(arr[i], end=" ")