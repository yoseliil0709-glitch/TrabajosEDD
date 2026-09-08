# Implementación en Python
# Inserción de un elemento al principio de un array
inputArr = [11, 21, 31, 41, 51, 61]
ele = 52
print("Antes de la inserción, el array es: ")
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")
# Inserción del elemento en el índice 0
inputArr.insert(0, ele)
print("\nDespués de la inserción, el array es: ")
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")