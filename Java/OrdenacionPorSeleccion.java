public class OrdenacionPorSeleccion {
    static void selection(int[] a) { // funcion para implementar el algoritmo de seleccion
        for (int i = 0; i < a.length; i++) { // recorre todo el arreglo
            int small = i; // indice del elemento mas pequeño
            for (int j = i + 1; j < a.length; j++) { // encuentra el elemento mas pequeño del arreglo
                if (a[small] > a[j]) { // compara el elemento mas pequeño con el siguiente
                    small = j; // actualiza el indice del elemento mas pequeño
                }
            }
            // intercambia el elemento mas pequeño con el primer elemento
            int temp = a[i]; // intercambia los elementos
            a[i] = a[small];
            a[small] = temp;
        }
    }

    static void printArr(int[] a) { // funcion para imprimir el array
        for (int i = 0; i < a.length; i++) { // recorre todo el arreglo
            System.out.print(a[i] + " "); // imprime el elemento
        }
    }

    public static void main(String[] args) {
        int[] a = {65, 26, 13, 23, 12}; // arreglo desordenado

        System.out.println("Arreglo antes de ser ordenado: ");
        printArr(a);

        selection(a);

        System.out.println("\nArreglo despues de ser ordenado: ");
        printArr(a);
    }
}