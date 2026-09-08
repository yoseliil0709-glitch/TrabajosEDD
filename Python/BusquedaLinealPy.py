# Implementación en Python
def findEle(inpuptArr, s, targetEle):
    for j in range(s):
        if (inpuptArr[j] == targetEle): # aplicando búsqueda lineal
            return j # elemento encontrado en el índice j
    # no se encuentra el elemento objetivo
    return -1

if __name__ == '__main__':
    inputArr = [12, 34, 10, 6, 40, 89, 98, 57, 19, 69]
    targetElement = 40
    s = len(inputArr)
    # operación de búsqueda
    idx = findEle(inputArr, s, targetElement)
    if idx!= -1:
        print("El elemento se encuentra en la posición: " + str(idx + 1))
    else:
        print("No se encuentra el elemento.")