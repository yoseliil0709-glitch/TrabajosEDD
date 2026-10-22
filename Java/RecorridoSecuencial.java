public class RecorridoSecuencial {
    public static void main(String[] args) {
        int[] arr = {40, 50, 60, 70, 80, 90};

        System.out.print("Recorrido lineal (secuencial): ");
        System.out.print("\nLos elementos del array son: ");

        // for-each = tu for idx in arr: de Python
        for (int idx : arr) {
            System.out.print(idx + " ");
        }
    }
}