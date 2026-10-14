class ShellShort {

    public static void displayArr(int[] imputArr) {
        for (int k : imputArr) {
            System.out.print(k + " ");
        }
        System.out.println();
    }

    public int sort(int[] imputArr) {
        int size = imputArr.length;
        int gapSize = size / 2;

        while (gapSize > 0) {
            for (int j = gapSize; j < size; j++) {
                int val = imputArr[j];
                int k = j;

                while (k >= gapSize && imputArr[k - gapSize] > val) {
                    imputArr[k] = imputArr[k - gapSize];
                    k = k - gapSize;
                }
                imputArr[k] = val;
            }
            gapSize = gapSize / 2;
        }
        return 0;
    }

    public static void main(String[] args) {
        int[] imputArr = {36, 34, 43, 11, 15, 20, 28, 45};

        System.out.println("Arreglo antes de ser ordenado: ");
        ShellShort.displayArr(imputArr);

        ShellShort obj = new ShellShort();
        obj.sort(imputArr);

        System.out.println("Arreglo despues de ser ordenado: ");
        ShellShort.displayArr(imputArr);
    }
}