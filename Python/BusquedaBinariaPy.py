# Implementación en Python - Búsqueda Binaria
def findEle(arr, l, h, targetValue):
    while l <= h:
        mid = l + (h - l) // 2
        # Verificar si x está presente en mid
        if arr[mid] == targetValue:
            return mid
        # Si targetValue es mayor que el elemento mid, considerar la segunda mitad del array
        elif arr[mid] < targetValue:
            l = mid + 1
        # Si targetValue es menor que el elemento mid, considerar la primera mitad
        else:
            h = mid - 1
    # Si el control llega hasta aquí, significa que el elemento no está
    return -1

if __name__ == '__main__':
    inputArr = [12, 34, 10, 6, 40, 89, 98, 57, 19, 69] # arrays de entrada
    targetElement = 40 # elemento objetivo a encontrar
    s = len(inputArr) # tamaño del array
    # operación de búsqueda
    idx = findEle(inputArr, 0, s - 1, targetElement)
    if idx!= -1:
        print("El elemento se encuentra en la posición: " + str(idx + 1))
    else:
        print("El elemento no se encuentra.")