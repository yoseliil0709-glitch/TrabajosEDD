public class OrdenPorColumnas2D {
    public static void main(String[] args) {
        // Implementacion por COLUMNAS en Java
        int r = 3;
        int c = 3;
        int[] arr = new int[r * c];

        int[][] TwoDArr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        // Almacenar elementos en un array unidimensional ordenados por COLUMNAS
        int k = 0;
        for (int y = 0; y < c; y++) { // primero columnas
            for (int x = 0; x < r; x++) { // luego filas
                arr[k] = TwoDArr[x][y];
                k = k + 1;
            }
        }

        System.out.println("Los elementos del array bidimensional son: ");
        for (int[] row : TwoDArr) {
            for (int ele : row) {
                System.out.print(ele + " ");
            }
            System.out.println();
        }

        System.out.println("\nLos elementos del array unidimensional por columnas son: ");
        for (int i = 0; i < r * c; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}