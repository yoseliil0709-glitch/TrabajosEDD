inputArr = [11, 21, 31, 41, 51, 61]

position = 3 # Índice desde el que se realizará la eliminación
del inputArr[position]

print("Antes de la eliminación, el array es: ")

for j in range(len(inputArr)):
    print(inputArr[j], end=" ")

# Eliminación del elemento en el tercer índice del inputArr[position]
print("\nDespués de la eliminación, el array es: ")

for j in range(len(inputArr)):
    print(inputArr[j], end=" ")