import java.util.Arrays;

public class Main {

    public static int findEle(int[] arr, int l, int h, int targetValue) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            // Verificar si x está presente en mid
            if (arr[mid] == targetValue) {
                return mid;
            }
            // Si targetValue es mayor que el elemento mid, considerar la segunda mitad del array
            else if (arr[mid] < targetValue) {
                l = mid + 1;
            }
            // Si targetValue es mayor que el elemento mid, considerar la primera mitad del array
            else {
                h = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] inputArr = {12, 34, 10, 6, 40, 89, 98, 57, 19, 69}; // arrays de entrada
        int targetElement = 40; // elemento objetivo a encontrar
        int s = inputArr.length; // tamaño del array

        Arrays.sort(inputArr);

        // operación de búsqueda
        int idx = findEle(inputArr, 0, s - 1, targetElement);

        if (idx!= -1) {
            System.out.println("El elemento se encuentra en la posición: " + (idx + 1));
        } else {
            System.out.println("El elemento no se encuentra.");
        }
    }
}