# Implementación en Python
# Programa para eliminar un elemento al final
inputArr = [11, 21, 31, 41, 51, 61]
print("Antes de eliminar, el array es: ")
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")
# Eliminando el elemento al final inputArr.pop()
inputArr.pop()
print("\nDespués de eliminar, el array es: ")
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")