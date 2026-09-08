# Implementación en Python
TwoDimensionalArray = [
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]
]

print("Los elementos del array son: ")
for row in TwoDimensionalArray:
    for element in row:
        print(element, end=" ") # mostrando los elementos de la fila separados por espacios
    print() # Ir a la siguiente línea después de mostrar una fila