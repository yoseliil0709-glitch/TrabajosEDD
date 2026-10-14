class ShellShort:
    @staticmethod
    def displayArr(imputArr):
        for k in imputArr:
            print(k, end=" ")
        print()

    def sort(self, imputArr):
        size = len(imputArr)
        gapSize = size // 2
        while gapSize > 0:
            for j in range(gapSize, size): # <- aquí faltaba :
                val = imputArr[j]
                k = j
                while k >= gapSize and imputArr[k - gapSize] > val:
                    imputArr[k] = imputArr[k - gapSize] # <- =
                    k = k - gapSize # <- =
                imputArr[k] = val
            gapSize = gapSize // 2 # <- =
        return 0

if __name__ == "__main__":
    imputArr = [36, 34, 43, 11, 15, 20, 28, 45]
    print("Arreglo antes de ser ordenado: ")
    ShellShort.displayArr(imputArr)
    obj = ShellShort()
    obj.sort(imputArr)
    print("Arreglo despues de ser ordenado: ")
    ShellShort.displayArr(imputArr)