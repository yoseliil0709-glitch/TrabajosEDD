def merge(a, l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = [0] * n1
    R = [0] * n2

    for i in range(0, n1):
        L[i] = a[l + i]

    for j in range(0, n2):
        R[j] = a[m + 1 + j]

    i = 0
    j = 0
    k = l

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1

def mergeSort(a, l, r):
    if l < r:
        m = (l + r) // 2
        mergeSort(a, l, m)
        mergeSort(a, m + 1, r)
        merge(a, l, m, r)

# Programa principal
a = [12, 11, 13, 5, 6, 7]
s = len(a)

print("Antes de ordenar el arreglo: ")
for j in range(s):
    print("%d" % a[j], end=" ")

mergeSort(a, 0, s - 1)

print("\nDespues de ordenar el arreglo: ")
for j in range(s):
    print("%d" % a[j], end=" ")